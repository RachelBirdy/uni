Setting up a relationship between animals and keepers.

This is a many to many relationship. Animals may have multiple keepers, and keepers may have multiple animals.

Unline one to one, and one to many relationships, we many to many relationships we don't know how many relationships exist on either side.

The only way we can set this up in a database is with a pivot table. This is a table that sits between the two tables and contains the relationships between animals and keepers. It has two collumns; one for the keeper foreign key and one for the animal foreign key. You know this concept, the only new information here is that it's called a pivot table.

A pivot table is essentially a pair of one to many relationships - Each pivot can only have one keeper, but one keeper can have many pivots. And, each pivot can only have one animal, but every animal can have multiple pivots.

We make the keeper model with
`sail artisan make:model keeper -m`
Remember, the -m creates the migrations file

The migrations are where the database is defined, add your fields here.

For the pivot table, we want a migration file to make the table but we don't need a model accompanying it. To do this, rather than using `make:model` we use:
`sail artisan make:migration create_animal_keeper_table`

Pivot table convention says that the model names being connected should be in alphabetical order, and should be named singularly rather than plural.

Pivot tables shouldn't have a dedicated primary key field; rather we use a composite key of the two keys being linked. So in the migrations file remove the automatically generated `id` field and add:
`$table->primary(['animal_id', 'keeper_id']);`
Again, it is important that these are in alphabetical order

Then we need to add referential constraints. with:
`$table->foreign('animal_id')->references('id')->on('animals')->onDelete('cascade')->onUpdate('cascade');`

In the Animal model php file, we can make:
`public funcion keepers() {`
`    return $this->belongsToMany(Keeper::class);`
`}`

If you get errors when creating tables, the first thing to check is the order tables are created in. If they are created in the wrong order, you can change the order by changing the date at the start of the name of the migrations file.

Seeding is tricky;
Create a seeder with artisan. Then, to join the tables together uhhh. Check the recording for this. Can't write clearly enough.

The pivot table can contain more data than just the id's. For instance, if the animal-keeper relationship is defined by different people being on duty on different days, you could add a day column to the pivot table. If you're going to be accessing the data of the pivot table though, it may be better to make a model to accompany it rahter than just a table.

## Factory relationships

Look at the documentation for this, which is linked from the slides. The lecture is currently sean going through the official documentation rather than using the animals example.

*undertale voice* factories can call other factories