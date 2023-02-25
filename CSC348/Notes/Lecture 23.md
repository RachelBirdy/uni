# AAAAAAAAAAAAAAAAAAAAAAAAAAA

## aaaaaaaa?

### Webapps!
Security time! For to do service containers later but for RIGHT NOW it is security! We sing the tale of Bobby Tables!

Laravel makes things secure, mostly, which is why it hasn't come up much.

It's not just making sure your thing is secure, but also don't accidentally make something people can use to do bad things to other people.

### THreat modelling oh boy lets go
THe first step is to identify what the possible security risks are. Threat modelling helps provide a structure to do this. A threat obly becomes a  vulnerability when it's likely to happen. There are three steps:
1. Break down your application into component parts and understand
a) How they interact with eachother
b) How they interact with the outside world.
2. Analyse each component for securyt problems. (STRIDE)
3. Prioritise the problems (DREAD)
4. Act upon then.

STRIDE is an acronym:
·Spoofing - Can something like a bot pretend to be someone or something else
·Tampering - Can data be maliciously changed
·Repudiation - Is it possible for an action to be undertaken and the person who did it claim they didn't do it
·Information Disclosure - Is it possible for information to be read by someone who does not have legitimate access?
·E

DREAD is also an acronym that is used to quantify risk and prioritise which vulnerabilities to address
·Damage potential - how bad would it be if this was exploited?
·Reproducability - how hard is it to reproduce?
·Exploitability - How easy is it to do?
·Affected users - How many people are impacted by it
·Discoverability - security through obscurity baybee.

XSS is cool

Passive injection - is when this unsanitised input is saved in a database and displayed to other users.

Active injection is when the unsanitised input is immediately displayed onscreen.

Browsers diliberately restrict the access javascript has to a users operating system and files