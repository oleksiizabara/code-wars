    var noQuestion = false;
    var incrimentInterval = 1000;   
    
    var app = angular.module('app', []);

    app.directive("gamestart", function(){
        return {
            restrict: "E",
            template: "<button creategamedirective>почати гру</button>"
        }
    });

    app.directive("creategamedirective", createGameDir);

    app.directive('gamecontainer', addGameTemplate);

    function createGameDir($compile) {
        return function(scope, element, attrs){
            element.bind("click", function(){
                $('.game_option').hide('slow');
                angular.element(document.getElementById('gc')).append($compile("<div id='game_container' gamecontainer></div>")(scope));
            });
        };
    }

    function addGameTemplate() {
        return {
            templateUrl: "/gamet/game_template.html",
            link: function(scope, element, attrs) {
                    console.log('adding template');
                }
        }   
    }

    app.controller('task', startGame);

    function startGame($scope, $timeout, dataExchange) {
        $scope.dataExchange = dataExchange;
        dataExchange.points = $scope.gamerCurrentPoints;
        dataExchange.level = $scope.gamerCurrentLevel;
           
        $scope.time = 7;
        $timeout(timer, incrimentInterval); 

        if ($scope.firstQuestion == "") {
            addSorryDiv();
        }

        var uservariant = "";

        $(document).on("click", ".variant", function () {
            $('.questions').hide();
            var answer = "";

            if ($(this).attr('id') === "f") {
                answer = $scope.firstQuestion;
            } else if ($(this).attr('id') === "s") {
                answer = $scope.secondQuestion;
            }

            var number = $scope.numberOfQuestion;
            var numberid = document.getElementById("numberid").value;
            

            $.ajax({
                url: '/hutercheckresult',
                type: "get",
                data: {
                    "data": answer,
                    "number": number,
                    "numberid": numberid
                },
                success: afterSend
            });
        });

        function afterSend(data) {
            congratulate(data);
            getNewQuestion();
        }

        function getNewQuestion() {
            console.log("start get data");
            
            $.ajax({
                url: '/getquestion',
                type: "get",
                dataType: 'json',
                success: getQuestion
            });
        }

        function getQuestion(data) {
            $('.questions').show();
            console.log("data-new", data);
            $scope.time = 7;
            $timeout(timer, incrimentInterval);
            if (data.FirstQ === "") {
                addSorryDiv();
            } else {
                $('.questions').show();
                $('.timer').show("slow");
                $('.sorry').hide("slow");
            }

            $scope.$apply(function () {
                $scope.firstQuestion = data.FirstQ;
                $scope.secondQuestion = data.SecondQ;
                $scope.numberOfQuestion = data.NumberQ;
                $scope.gamerCurrentPoints = data.Points;
                $scope.gamerCurrentLevel = data.Level;
                $scope.interestFact = data.Interest;
            });
            $scope.dataExchange = dataExchange;
            dataExchange.points = $scope.gamerCurrentPoints;
            dataExchange.level = $scope.gamerCurrentLevel;

            $('#i').show();
        }

        function timer() {
            $scope.stopTimer = function() {
                console.log("stoptimer");
                $timeout.cancel(callbackTimer);                        
            };
            $scope.stopGame = function() {
                location.reload();
            }
            if( $scope.time > 0 ) {
                $scope.$apply(function () {
                    $scope.time -= 1;
                });
                callbackTimer = $timeout(timer, incrimentInterval);
            } else {
                getNewQuestion();
            }
        }

        function waitSomeTime() {
            $timeout(getNewQuestion, incrimentInterval*3)
        }
    }

    function congratulate(data) {
        if (data === "ok") {
            console.log("true");
        } else {
            console.log("false");
        }
    }

    function addSorryDiv() {   
        $('.questions').hide("slow");
        $('.timer').hide("slow");
        if (!noQuestion){
            $('<div/>', {
                class: 'sorry',
                text: 'нажаль не залишилось питань'
            }).appendTo('#q');
            noQuestion = true;
        }  
    }

    app.controller('userValues',function($scope, dataExchange){
        $scope.dataExchange = dataExchange;
        $scope.gamerCurrentPoints = dataExchange.points;
        $scope.gamerCurrentLevel = dataExchange.level;
    });

    app.factory('dataExchange', function() {
        var startPoints = $("#pp").val();
        var startLevel = $('#ll').val();

        return {
            points: startPoints,
            level: startLevel
        }
    })