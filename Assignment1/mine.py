import hashlib
import time
inp = input("Enter a string: ")
start_time=time.time()
for x in range(2**256):
    mod=inp+str(x)
    result=hashlib.sha256(mod.encode()).hexdigest()
    if int(result,16)<=(0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF):
        end_time=time.time()
        print("Time taken =",end_time-start_time)
        print("Appended number =",x)
        print("Result =",result)
        break
