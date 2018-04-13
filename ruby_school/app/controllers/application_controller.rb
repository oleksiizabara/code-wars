class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception

  # before_filter :authorizet

  # protected

  # def authorizet
  #   unless User.find_by_id(session[:user_id])
  #     redirect_to login_teacher_path, notice: 'Please login us teacher'
  #   end
  # end
end
