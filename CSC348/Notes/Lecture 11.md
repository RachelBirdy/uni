# LAST TIME, ON CS348...

We had a table of animals, and we had a table of emergency contacts. We set up a one to one relationship between them. If we follow Laravel's conventions, it does a lot of things automagically for us! 

# And now, the conclusion...

As with anything else you want to test, you test with `tinker`!

Remember, Tinker is run with `sail tinker`. Use tinker to test out commands before you run them!

When you run tinker, the first thing you need to do is import the relevant namespaces. For this example that means running, inside tinker:
`use App\Models\Animal;`
and
`use App\Models\EmergencyContact;`

You can assign specific objects to variables using something like:
`$a = Animal::find(1);`
and
`$ec = EmergencyContact::find(1);`

These will find the first animal and emergency contact and assign them to variables

We added a function emergencyContact to the Animal class to find an animals emergency contact, so we can run:
`$a->emergencyContact` to get the emergency contact object connected to the animal.

We also implemented the inverse in emergencyContact, so we could run `$a->emergencyContact->animal` to get back to the current animal if we want to.

As an asside, it's important to understand what you're doing. For instance, making the animal id in EmergencyContact nullable may prevent some sql errors if your implementation is wrong, however you've made it possible for an emergency contact to not have an animal, which doesn't make sense. This is not an appropriate solution, in this case. In some cases though it may make sense to allow a foreign key to be nullable, if not all instances of the class will necessarily have an associated object from the other class.

## One to many relationships

Every animal needs an enclosure. However, one enclosure can have many animals.

We can entirely define this relationship with a foreign key in the animals table.

Coursework should be screenshots in a word document submitted as a pdf. The marking ruberick kindof gives away what files you need to submit.

Make the enclusure model with:
`sail artisan make:model Enclosure -m`
Then go to your animal migrations file and add the reference to the enclosure foreign key.

Then we can add a method `animals()` to our Enclosure model to get all the animals in the enclosure.

If we have followed laravel's naming conventions, we can use a laravel magic method:
`public function animals() {`
`    return $this->hasMany(Animal::class);`
`}`

And as with emergency contacts, we can define the inverse by adding to the animal class:
`public function enclosure() {`
`    return $this->belongsTo(Enclosure::class);`
`}`

We can also make a seeder, using
`sail artisan make:seeder EnclosureTableSeeder`

Remember to call the seeder from the `DatabaseSeeder.php` file!

# Thats all!