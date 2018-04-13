class CreateMarks < ActiveRecord::Migration[5.1]
  def change
    create_table :marks do |t|
      t.string :for_pupil_id
      t.string :subj
      t.date :date
      t.integer :value
      t.timestamps
    end
  end
end
