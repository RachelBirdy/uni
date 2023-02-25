## This time, on CSC348...

# BLADE

Time to do the frontend baybee.

THe routing is defined in the file web.php

Each route calls a function. The default routes return anonymous functions that return views.

In the resources folder, these views can be found. These are blade.php files, and they use the blade templating engine. A blade template is mostly normal html EXCEPT it is extended to allow logic.

Remember, laravel is an MVC framework. We have done the M, we are now doing the V.

"Views are your web pages" are a bad definition that will lose marks. Research a better definition.

Views allow us to create layouts and templates so that we don't have to repeat code. For instance, if we have a sidebar across the entire site we do not need to copy that code to every page.

Sean wants us to think of a view as a php method/class/whatever that returns a string that contains the webpage.

Laravel converts blade files into php and caches them until they are updated

Unlike other templating engines, you can still use plain php in views. This is a bad idea, blade has ways to make things less messy than php.

Views can be passed named values. For instance you can say `return view('welcome', ['name'=>'Samantha']);`

ANd then within the view you can reference that with `Hello, {{ $name }}`

You can also put php methods in these curly braces, for instance `The current UNIX timestamp is {{ time() }}.`

There are if statements. If statements can ahve an unless term. There are loops. Love the loops.

because you can write logic in your view, sometimes its east to write too much logic in your view. The logic should go in the controller.

!!There is a simple view example in the slides taht shows a list of animals. I want this for the music index thing!

As a part of the coursework: Users should only be able to edit their own posts, unless they are an admin. This involves logic inside the view.