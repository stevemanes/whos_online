# whos_online

The Who's Online Now (whos_online) module is a replacement for Drupal's core
Who's Online block in the Users module.  There are several improvements over
the stock Who's Online block.


Dependencies
------------
This module has two critical dependencies.  Don't even think about installing
it unless you are running the following on your web server:

* PHP 5.2 or later,

* Memcached.

* A properly configured cron tasker.

THIS MODULE WILL NOT WORK WITHOUT THEM!

Overview
--------
Who's Online Now breaks out users into one of three types: registered users,
guests and known bots.

* Registered users are assembled from the user's environment, saving one
database query per page.

* Guests are broken out into a list of IP addresses or alternatively by hostname.

* Bots are identified by the "User Agent" header they send with the HTTP request.
The bot list is downloaded periodically from http://www.user-agents.org, the
most complete internet list of bots, spiders and browser user agents.

Jquery drives the block display.

Knowing which bots hit your site and how often can help you identify misbehaving
spiders and spam bots which are sucking unnecessary bandwidth.  Ideally, this
should be done via server log parsing but Who's Online Now will give you a heads
up in (almost) real time.

Most of the heavy lifting in Who's Online Now is done by the cron task.  Ideally,
your cron task should launch every 15 minutes to keep the Who's Online Now list
reasonably current.

Cron is also responsible for automatically downloading and installing an updated
user agent list.  Since updates to the master XML file on user-agents.org appear
to happen only four or five times a year, there's not much point in setting the
"Download new user agents master file" more frequently than once a month.  If
this file is missing however, cron will attempt to download it immediately.

Be sure that the local directory you've selected to cache this file is writable
by the web server.

You can also add additional user agents of your own to an "agents_addl.txt" file
located in this directory.  This file has two logical columns: the literal user
agent string sent by the browser and a description of the agent for display.  The
two columns are delimited by ^|^.

Examples:
Sogou web spider/4.0(+http://www.sogou.com/docs/help/webmasters.htm#07^|^Sogou web spider
Mozilla/5.0 (compatible; Charlotte/1.1; http://www.searchme.com/support/^|^SearchMe spider

When the cron task sees an update to the agents_addl.txt file it will automatically
reload it.


Install
-------
Installing the Who's Online Now module is simple:

1) Copy the whos_online folder to the modules folder in your installation.

2) Enable the module using Administer -> Modules (/admin/build/modules).

3) Configure role permissions in Administer Permissions (/admin/user/permissions).

No database update is needed.

WARNING: be aware that enabling hostname display can be costly.  The web server
has to make a DNS request for each new connection.  The hostname is cached so
this is only done once for the user.  However on a very busy site this could be
a moderate performance bottleneck.

If you are only running one Drupal site on your web server you can use the
default "Memcached ID".  Otherwise, each site should be assigned a unique
text token like "0001", "0002", "SITE9".  The master user agents list is
shared by all Drupal instances.


Modifying
---------
You can change the colors/look of the Who's Online Now block in whos_online.css.

