## Creating data baybee.

The course is going to be quick from here, the scaffolding is being taken away so that we can ride our scaffolding-less bikes on our own. I think these metaphors are getting slightly mixed up...

When we start to create views which allow users to create data, things will break. Therefore, we need to use `debugging toooooools!!!`

Debugging is tricksy because you can't just output something to a command line

Live coding time. Again.

The laravel debugging tool is `dd`, which stands for dying dump.

Because laravel has a middleware pipeline, dd can go in at any point and pull a response which is neat. dd will return a fairly nicely formatted html page with the relevant data.

But anyway

Remember get and post methods?

GET is what we use to get resources
HEAD is less useful, it is to get a response to a GET response minus the body of the response
POST is to put data in the database
PUT
PATCH
DELETE

### RESTful systems
REST stands for REpresentational State Transfer

Sean is giving an example of a system is not RESTful.

RESTful systems are like goldfish, they dont remeber anything and you have to re-explain everything with every request, which is generally a good thing and prevents things from getting mixed up

Convention is that to get a model, the path should be /{pluralmodelname}

Sean is explaining how different requests are used to store data. I feel like the lecture recording will explain this better than I can type.