# Big Integer (C++)
A class implementation of an unsigned integer with a size of 1024 bits. 

### Constructors
```explicit BigInt(void)```: sets the bitset's value to all 0's.

```explicit BigInt(const unsigned long long& num)```: sets the bitset's value to the binary representation of ```num```.

```explicit BigInt(const std::string& str)```: Takes a string representation of a decimal, binary, or hexadecimal number. In order to differentiate the representations binary and hexadecimal must be preceded with ```0b``` and ```0x``` respectively.

```explicit BigInt(const BigInt& n)```: copy constructor

### Methods
This implementation contains every operator available to standard integers with their effects being identical to that of standard integers. The operators ```&=```, ```|=```, ```^=```, ```<<=```, ```>>=```, ```&```, ```|```, ```^```, ```<<```, ```>>```, ```~```, ```==```, ```!=``` were provided from C++'s standard bitset. 

Every other operator needed to be implemented by hand. Addtionally, every operator that was hand implemented in ```BigInt.hpp``` was implemented in a bitwise manner. 

All methods that needed to be implemented from ```int``` to ```std::string``` conversions are defined in ```bits2str.hpp```. These methods include hexadecimal strings to binary, bitset to decimal string, and decimal string to binary. 

### Include
This class can simply be included to any C++ file by including ```BigInt.hpp```. However ```BigInt.hpp``` and ```bits2str.hpp``` must be in the same directory. 

### Additional Info
This class can create integers with any binary length representation. I have that length set to 1024. However, if you need a higher precision integer, you can change ```BITS``` on line 18 of ```bits2str.hpp``` to any length.

The maximum unsigned integer with a binary representation of size 1024 is:
179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137215