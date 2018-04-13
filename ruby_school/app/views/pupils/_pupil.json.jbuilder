json.extract! pupil, :id, :login, :name, :password, :created_at, :updated_at
json.url pupil_url(pupil, format: :json)
