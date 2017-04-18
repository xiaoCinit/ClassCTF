# DMZ server1
privilege issue, when user login server through ssh, they can access to the /var/www/html directory, and bypass the first challenge.

[+] I dont konw how to do that

~~[+] modify the vimjail flag, add hint [done]~~

# DMZ server2

privilege issue:

  1. when user exploti proftp service, they will get a shell belongs to www-data, this shell can access to /var/www/html file.[I think it's not a big issue? maybe? add privilege limit on /var/www/?]

~~2. when execute exploit to attack proftp, the directory of /var/www/html must be writable. check its security issue..~~ [it seems ok]
 
  ~~3. start ftp service automatically~~ [done]

# Gate

~~1. login as unprivilege user(can't sudo)~~ [remove the sudo privilege of evilc, add a new secret user]

~~2. find a new challenge, setuid or something, escalate privilege, become root user~~ [RE move to Gate]
 
# Windows server

~~1. setup new version (less vulns)~~  [but exploit cannot execute]? why?

~~2. create flag.txt~~ [done]
 
# personnal laptop

~~1. install ssh-server and client.~~ [done]

~~2. install RE challenge into it.~~ [change to dirtycow done]
  

## Deadline: This ~~Monday.~~ Tuesday
