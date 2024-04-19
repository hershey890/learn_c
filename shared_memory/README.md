Creates a shared buffer to be shared between to processes, send and receive. The send process takes the shm buffer name as well
as the string to put into the shared buffer as input args. After this is done, the sending process increments a semaphore
that was initalized as 0 to inform the receiving process that it is done taking and sending the inputs. 
The receiving process then makes these uppercase and increments its own semaphore (which also started out as 0) to inform
the sending process that it is done procesing the input and making it uppercase after which both processes exit successfully.  

To run:
```
$ make -C ../build/
$ ../build/shared_memory/pshm_receive /myshm & 
[3] 739756
$ ../build/shared_memory/pshm_send /myshm hello
HELLO
[2]   Done                    ../build/shared_memory/pshm_receive /myshm
[3]-  Exit 1                  ../build/shared_memory/pshm_receive /myshm
```  
  
Also read later:  
https://stackoverflow.com/questions/59132799/is-it-possible-to-use-fork-in-modern-c  
https://web.archive.org/web/20170608235510/https://www.linuxprogrammingblog.com/threads-and-fork-think-twice-before-using-them  
