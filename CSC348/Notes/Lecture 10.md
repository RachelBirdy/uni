# Lecture 10

## Model Relationships Baybee.

Recap: Models are responsible for managing our data.

In laravel we mainly define our models in database migration files.

We also have a PHP class representing each model, that class implements the Active Record design pattern, whihc means that every class ins responsible for itneracting for the whole table

Laravel's Eloquent library means we can use any database we want because we don't need to write SQL ourselves

To test our application we used seeding and made factories

## Building relaitonships between models

It may be worth looking over Y2 database notes for this

It gets complex but:
·First decide what type of trlaionship you need

·Define the database key relationships in the migration files

·Create methods in our model classes to automatically perform the relationship based queries

For instance, "I am one user posting many tweets on twitter" means users have a one to many relationship with tweets. We define this in our migrations file.

One to one examples - Animals and Emergency Contacts. Every animal has one emergency contact and every emergency contact has one animal.
One to many example - Enclosures to animals. One enclosure has many animals but every animal has one enclosure.
Many to many example - Animals and Keepers. Every animal may have many keepers and every keeper looks after many animals.

<b>COURSEWORK SHOULD HAVE EXAMPLES OF ALL THREE RELATIONS</b>

Remember, to make a model you use `sail artisan make:model EmergencyContact -m`

To create a foreign key, first create a table entry for the foreign key. For instance, in the emergency contacts table add `$table->bigInteger('animal_id')->references('id')->on('animals');`
MANY YOUTUBE TUTORIALS WILL OMIT THE REFERENCE ASPECT

Laravel's convention for foreign keys is `<model_name>_<field>`

This will throw an error if the animal ID doesn't exist. This is good. You want to catch bugs early, during testing, rather than kick then down the road for the user to experience.

We also need to explain what behaviour we want to see if the foreign key is deleted. So we need to add to our entry.
`$table->bigInteger('animal_id')->references('id')->on('animals')`
`    ->onDelete('cascade')->onUpdate('cascade');`
Cascade means that any changes are propegated/cascaded to other models.

However, this means that if an enclosure with this constraint is deleted, all animals will be deleted too. Or, if you change an enclosure's id all animals will be updated.

Instead, another option is to use `restrict`, which prevents these changes from being made.

## Magic Methods
Laravel has what are called `Magic methods` and oh god is this going to be some JavaScript promises type bullshit isnt it :(
In the Animal class you can add a function;
`public function evergencyContact() {`
`    return $this->hasOne(EmergencyContact::class);`
`}`

`hasOne` is a method that, provided we have followed Laravel's naming conventions, will automatically write the sql relationship to get the relation between the classess. It provides an object oriented way of accessing the related data. It is the equivalent of a getter for a reference to another object.

The emergency contact belongs to the animal. Kinda hot.

To get the inverse relationship we can add a method to the animal class;
`public function animal() {`
`    return $this->belongsTo(Animal::class);`
`}`

`belongsTo()` gets the inverse of `hasOne()`

## Gotchas/misc

The foreign key must match the tupe of the primary key it refers to. This may be different in different laravel versions, so be wary of tutorials.
The order of migrations matter! If you create a table with a foreign key to another table before the other table exists, it will break.
`sail artisan list` will give a list of commands
Remember, you can change the order of migrations by changing the filename! The order is absed on teh date at the start of the migrations file name. This is the most janky aspect of laravel.

## Seeding

Like with previous seeders, it is useful to create some hard coded values for testing with known, repeatable values.

## NEXT TIME, ON CS348
We will look at how to use relationships or, idk, I didn't quite catch what he said >.>