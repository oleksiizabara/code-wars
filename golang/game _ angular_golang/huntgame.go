package routes

import (
	"encoding/json"
	"fmt"
	"math/rand"
	"net/http"
	"social/db/documents"
	"social/models"
	"social/session"
	"strconv"
	"time"

	"github.com/martini-contrib/render"
	"gopkg.in/mgo.v2"
)

type GameInfo struct {
	FirstQ   string
	SecondQ  string
	NumberQ  int
	Interest string
	Points   int
	Level    int
}

func StartHunterGame(rnd render.Render, s *session.Session, db *mgo.Database) {
	if !s.IsAuth {
		rnd.Redirect("/")
		return
	}
	model := models.HuntGame{}

	model.IsAuth = s.IsAuth
	model.IfTeach = s.IfTeach
	model.IfPupil = s.IfPupil
	model.IfParent = s.IfParrent
	model.UserOnline = s.Username
	model.PhotoUser = s.UserPhoto
	loadedGame := documents.HuntGame{}

	db.C("app-hunting").FindId("huntinggame").One(&loadedGame)

	ifUserInGame := false
	gamer := documents.Gamer{}

	for i := 0; i < len(loadedGame.Gamers); i++ {
		if loadedGame.Gamers[i].Login == s.Username {
			gamer = loadedGame.Gamers[i]
			ifUserInGame = true
			break
		}
	}
	if !ifUserInGame {
		newGamer := documents.Gamer{}
		newGamer.Login = s.Username
		newGamer.Points = 0
		newGamer.Name = s.RealUserName
		newGamer.Level = 0
		newGamer.NumberId = len(loadedGame.Gamers)
		newGamer.Location = loadedGame.Locations[0]
		newGamer.TimeBlock = false
		newGamer.TimeWait = 0

		gamer = newGamer
		loadedGame.Gamers = append(loadedGame.Gamers, newGamer)
		db.C("app-hunting").UpdateId("huntinggame", loadedGame)
	}
	curentTime := time.Now().Unix()
	if gamer.TimeBlock {
		if gamer.TimeWait+86400 <= curentTime {
			gamer.TimeBlock = false
			gamer.TimeWait = 0
			gamer.AnsweredWrong = nil
			loadedGame.Gamers[gamer.NumberId] = gamer
			db.C("app-hunting").UpdateId("huntinggame", loadedGame)
		}
	}

	model.Gamer.Points = gamer.Points
	model.Gamer.Level = gamer.Level
	model.Gamer.Login = gamer.Login
	model.Gamer.Name = gamer.Name
	model.Gamer.NumberId = gamer.NumberId

	rand.Seed(time.Now().Unix())

	questions := []documents.Question{}
	for i := 0; i < len(loadedGame.Questions); i++ {
		if loadedGame.Questions[i].ForLevel == gamer.Level {
			fmt.Println("question", loadedGame.Questions[i])
			ifAnswered := false
			ifAnsweredWrong := false
			for t := 0; t < len(gamer.Answered); t++ {
				if gamer.Answered[t] == loadedGame.Questions[i].Number {
					ifAnswered = true
					break
				}
			}
			for t := 0; t < len(gamer.AnsweredWrong); t++ {
				if gamer.AnsweredWrong[t] == loadedGame.Questions[i].Number {
					ifAnsweredWrong = true
					break
				}
			}
			if !ifAnswered && !ifAnsweredWrong {
				questions = append(questions, loadedGame.Questions[i])
			}
		}
	}
	rand.Seed(time.Now().Unix())
	fmt.Println("questions all", questions)
	if len(questions) != 0 {
		question := questions[rand.Intn(len(questions))]
		model.Question = question
	}

	rnd.HTML(200, "app-hunting", model)
}

func CheckDataHunter(rnd render.Render, s *session.Session, db *mgo.Database, r *http.Request) string {

	if !s.IsAuth {
		rnd.Redirect("/")
		return "wrong"
	}
	variant := r.FormValue("data")
	numberOfQuestion, _ := strconv.Atoi(r.FormValue("number"))
	numberId, _ := strconv.Atoi(r.FormValue("numberid"))

	loadedGame := documents.HuntGame{}
	db.C("app-hunting").FindId("huntinggame").One(&loadedGame)

	question := loadedGame.Questions[numberOfQuestion-1]
	gamer := loadedGame.Gamers[numberId]

	if variant == question.CorrectVariant {
		gamer.Points++
		gamer.Answered = append(gamer.Answered, numberOfQuestion)
		if gamer.Points > 0 && gamer.Points%20 == 0 {
			gamer.Level++
			gamer.Location = loadedGame.Locations[gamer.Level]
		}
		loadedGame.Gamers[numberId] = gamer
		db.C("app-hunting").UpdateId("huntinggame", loadedGame)
		return "ok"
	} else {
		if gamer.Points > -5 {
			gamer.Points--
		}
		if gamer.Level != 0 && gamer.Points < gamer.Level*20 {
			gamer.Level--
		}
		gamer.AnsweredWrong = append(gamer.AnsweredWrong, numberOfQuestion)
		if !gamer.TimeBlock {
			gamer.TimeBlock = true
			gamer.TimeWait = time.Now().Unix()
		}
		loadedGame.Gamers[numberId] = gamer
		db.C("app-hunting").UpdateId("huntinggame", loadedGame)
		return "wrong"
	}
}

func GetNewQuestion(w http.ResponseWriter, rnd render.Render, s *session.Session, db *mgo.Database) {
	var question documents.Question
	if !s.IsAuth {
		rnd.Redirect("/")
		return
	}

	loadedGame := documents.HuntGame{}

	db.C("app-hunting").FindId("huntinggame").One(&loadedGame)

	gamer := documents.Gamer{}

	for i := 0; i < len(loadedGame.Gamers); i++ {
		if loadedGame.Gamers[i].Login == s.Username {
			gamer = loadedGame.Gamers[i]
			break
		}
	}

	curentTime := time.Now().Unix()
	if gamer.TimeBlock {
		if gamer.TimeWait+86400 <= curentTime {
			gamer.TimeBlock = false
			gamer.TimeWait = 0
			gamer.AnsweredWrong = nil
			loadedGame.Gamers[gamer.NumberId] = gamer
			db.C("app-hunting").UpdateId("huntinggame", loadedGame)
		}
	}

	rand.Seed(time.Now().Unix())

	questions := []documents.Question{}
	for i := 0; i < len(loadedGame.Questions); i++ {
		if loadedGame.Questions[i].ForLevel == gamer.Level {
			fmt.Println("question", loadedGame.Questions[i])
			ifAnswered := false
			ifAnsweredWrong := false
			for t := 0; t < len(gamer.Answered); t++ {
				if gamer.Answered[t] == loadedGame.Questions[i].Number {
					ifAnswered = true
					break
				}
			}
			for t := 0; t < len(gamer.AnsweredWrong); t++ {
				if gamer.AnsweredWrong[t] == loadedGame.Questions[i].Number {
					ifAnsweredWrong = true
					break
				}
			}
			if !ifAnswered && !ifAnsweredWrong {
				questions = append(questions, loadedGame.Questions[i])
			}
		}
	}
	rand.Seed(time.Now().Unix())

	fmt.Println("questions all", questions)
	if len(questions) != 0 {
		question = questions[rand.Intn(len(questions))]

	}

	interest := loadedGame.InterestFacts[rand.Intn(len(loadedGame.InterestFacts))]

	gameInfo := &GameInfo{FirstQ: question.FirstVariant,
		SecondQ:  question.SecondVariant,
		NumberQ:  question.Number,
		Interest: interest,
		Points:   gamer.Points,
		Level:    gamer.Level}

	jData, err := json.Marshal(gameInfo)
	if err != nil {
		panic(err)
		return
	}
	w.Header().Set("Content-Type", "application/json")
	w.Write(jData)
}
