# Writeup for Reverse Engineering Challenge

## Step1
Use command "file hack" to figure out the target's file type, it is a elf file. 
## Step2
Run this file with commands "chmod +x hack" and “./hack"
##Step3
Use disassembler to find more information.
##Step4
* After reading this code, we know that this code is used to check the content of a file whether equals to assigned words.
* So, we need to find this file's name and create it, and then try to figure out target words, and write these words into this file.
* File's name is "EthicalHacking". 
* Accoding to the code, we need to write down "entereky" into the file EthicalHacking
![keygen](http://ooj03jwxf.bkt.clouddn.com/aaaa.jpg)

* According to the code, Caesar cipher is used to protect the real words, it turns a to d, b to e, etc. So the fial value is "makeUSAgreatagain" . We need to write down this value in the file EthicalHacking.
![](http://ooj03jwxf.bkt.clouddn.com/bbbbbb.jpeg)
* Run this file again "./hack EthicalHacking"
And the picture shows that "makeUSAgreatagain" is the password we are looking for.
![](http://ooj03jwxf.bkt.clouddn.com/Screen%20Shot%202017-04-16%20at%208.09.39%20PM.png)

