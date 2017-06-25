import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("No command line argument passed")
        exit(1)
    
    key = int(sys.argv[1])
    t = []
    print("plaintext: ",end='')
    plaintext = cs50.get_string()
    print("ciphertext: ",end='')
    for symbol in plaintext:
        if symbol.isalpha():
            t.append(caesar(symbol, key))
        else:
            t.append(symbol)
                
    print("".join(t))
    exit(0)

def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)
        
if __name__ == "__main__":
    main()