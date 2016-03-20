# LESSONS FROM C & C++

Different lessons with the following titles. 


---
### **global**: 
use of global variables w/ linked objects.

This code handles/modifies a global variables from different linked objects.
To run:

```bash
 cd global/linked 
 make clean && make
./exe
```

---
### **templates**: 
use of templates with linked objects :smiley:

To run:
```bash
cd templates
make clean && make
./tt.x
```

---
### **exceptions**: 
use of try/catch :trollface:
```c++
try{
...
}
catch{
...
}
```

---
### **backward-cpp**: 
reports the stack trace (it would be nice to report the line sentence of *every* call of the chain). :squirrel:


---
#### Quote:
> _A general rule of thumb is that your program spends 80% of its time running 20% of the code. Thus a good strategy for efficient coding is to write everything, profile your code, and optimize the parts that need it. Python’s profilers are great, and Cython allows you to do the latter step with minimal effort._ - Hoyt Koepke

---
