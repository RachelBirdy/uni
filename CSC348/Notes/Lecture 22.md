## Fancy Frontends!

Everything we've made so far looks like shit
Lets make it unshit

The main thing we're missing (appart from decent CSS skills) is the ability to do things without the whole page refreshing every time we click a submit button.

Currently if a user wanted to comment on a post, what would happen is

User requests post
laravel returns post form
User enters data and sends
Laravel processes data and returns a new view

But the whole page refreshes every time this happens.

### Client side scripting baybeeeee.

Rather than everything being done by PHP on the server, we're going to start having the browser interpret some scripting and do some things

`It Is Time For Java Script.`

JavaScript is interpreted, not compiles. It is extremely flexible.

We are being recommended to use Laravel LiveWire. It's like how Laravel lets us use SQL without using SQL except it's JavaScript. So. Uh. Guess we aren't using JavaScript? Hmm.

### Sean is going to gift us with some useful features of javascript

We need to know a bit about the HTML DOM (Document Object Model). It Is Time To Do Independant Learning! (Oh, this is just, how HTML tags work as a tree)

Javascript can change what is rendered on a page without refreshing the page. This is cool and good.

### Asynchronous Javascript And XML (AJAX)
This is "like" a library that allows javascript to make a request to a server. Ajax sends a request to a server and gets a response in usually JSON (JavaScript Object Notation)

It's asynchronous because lots of elements could be running at the same time

### Livewire
This is a full-stack framework for building modern web interfaces within laravel. What makes it special is that you can use all the things you've learn from Laravel without learning JavaScript.

Livewire works by using something called Components. COmponents work like mini controllers.

Sean is pulling examples from `laravel-livewire.com`. There is a quickstart. Use it.

A component is a php class and an associated blade file. These essentially work like php wrappers for javascript and ajax. It feels like a mini comtroller and view, by design. Components can the be dripped anywhere in you existing laravel views.

After the quickstart there's a reference, which is a list of everywhere the framework looks for your code. This is an inversion of control thing, it shows where all the hooks are.