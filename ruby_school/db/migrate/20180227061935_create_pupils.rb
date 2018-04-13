class CreatePupils < ActiveRecord::Migration[5.1]
  def change
    create_table :pupils do |t|
      t.string :login
      t.string :name
      t.string :password
      t,integer :classroom
      t.timestamps
    end
  end
end
