class SessionController < ApplicationController
  def new
  end

  def newp
  end

  def create

    user = User.find_by(login: params[:login])
    
    if user && user.password == params[:password]
      session[:user_id] = user.id
      session[:status] = 'teacher'
      redirect_to user, notice: "Welcome, #{user.name}"
    else
      redirect_to login_teacher_path, notice: 'Incorrect login or password'
    end
  end

  def createp

    user = Pupil.find_by(login: params[:login])

    if user && user.password == params[:password]
      session[:user_id] = user.id
      session[:status] = 'pupil'
      redirect_to user, notice: "Welcome, #{user.name}"
    else
      redirect_to login_pupil_path, notice: 'Incorrect login or password'
    end
end

  def destroy
    session[:user_id] = nil
    session[:status] = 'guest'
    redirect_to users_path, notice: 'Goodbye!'
  end
end
