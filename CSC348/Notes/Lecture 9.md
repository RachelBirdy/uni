# Lecture 9
## LAST TIME, ON WEB DEVELOPMENT...

We looked at authentication, because a lot of people mess that up in the past. Today we're going to look at models more.

<b>REMINDER:</b>
A model is a class that represents our data
It uses an ORN mapping to access the data
It represents a row in the database but also is used to get access to the whole database.

We used migrations to create database entries. Do not define your properties in the Animals.php class file, define them in the migration file that configures the database

## AND NOW...

We are looking at seeding.
Seeding automatically adds data to our database. It's all about sharing and testing the project. Ideally we want our project to be portable, we can send it to anyone else and it just works *without* having to send them the accompanying database file. So they run a command which sets up the database for them, and add their own data. Seeding is the process of generating and adding data to the database.

Oh boy we doing live coding.

The command to begin this is

`sail artisan make:seeder <Your seeder name, like AnimalTableSeeder>`

A seeder is created with a single public function called run, as a php file in the seeders folder. REMEMBER inversion of control. Laravel controls the flow of the program and we have to recognize where to insert our code. This is one place.

We need to import the Animal namespace. We then insert code in the run function to generate data and populate the table.

THIS FILE IS A PART OF THE FIRST COURSEWORK SUBMISSION, as it is a part of the setting up databases code.

There is also a databaseseeder file, which we need to edit the run method of to call the animal seeder

The code for this is: `$this->call(AnimalTableSeeder::class);`

To run the seeder we use the command `sail artisan db:seed`
This command also gives useful diagnostic output.

Model factories are used to create realistic, random data. These are made with `sail artisan make:factory AnimalFactory -m Animal`
The `-m Animal` tells laravel to link the new factory to the model Animal.

We're going to be using an open source library called Faker to generate dater. It's not a php library, but the laravel developers have written a php wrapper for it.

Missed a bit of the lecture due to shitposting in the module discord. Check recording.

The Factory definition function returns an array of key:value pairs. This is difficult to make notes on, watch the recording instead.

In addition to the fake data, it's good practice to have a few hard coded entries. This allows you to also automate testing for getting values since there are values you know will be present.

You call a factory from the seeder file with `Animal::factory()->count(50)->create();`

You can kill and recreate the database with `sail artisan migrate:fresh --seed`
This kills and re-seeds the database.

Time to look at Query Building. I am queer this should be easy.

Laravel's query builder is a fluid set of methods

A fluid set of methods means:
If you have a `class Foo`, this may have a lot of methods in them which all return the type `Foo`. This means that these methods can be chained.

For example:
If you have `Foo V = new Foo();`, you can call `V.M1().M2().M1()`, because every method returns a Foo. This means that if these are named gramatically and sensibly, these chained calls can be constructed gramatically. This is similar to building SQL statements in an english-resembling way. This is why it's called fluent, because it's like fluent english.

There are examples of this being used in context in the video.

NEXT TIME ON WEB DEVELOPMENT...
Look over database notes, many-many, one-many relationships e.t.c oh boy!