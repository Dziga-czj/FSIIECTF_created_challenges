# challenges_ctf
A repository regrouping all the challenges I created for the FSIIECTF.  
The CTF was hosted by the SecuritIIE and FSEC-SS, cybersecurity clubs of ENSIIE in France and APU in Malaysia.

## compromising functions
Are you able to get the eax value at the return of the last call to the other compromising function ?  
The hash used in the flag will be the string "thekeyis:value" hashed in md5.  
### writeup
Unfortunately the challenge is broken. In fact, it is intented to be solved with GDB. The problem is that GDB show different values of $eax, depending on the way to "get" to the return instruction.  
here are some examples :  


