Rails.application.routes.draw do
  controller :session do
    get 'login/teacher' => :new
    post 'login/teacher' => :create
    get 'login/pupil' => :newp
    post 'login/pupil' => :createp
    delete 'logout' => :destroy
  end

  resources :marks
  resources :pupils
  resources :users
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
  root to: 'users#index'
end
