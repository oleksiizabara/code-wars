class Pupil < ApplicationRecord
    validates :login, presence: true, uniqueness: true
end
