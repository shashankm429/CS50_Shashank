import cs50

def main():
    while True:
        print("How much change is owed?:")
        change = cs50.get_float()
        if change >= 0:
            break
    
    coinsNumber = 0
    Change = int(round(change * 100))
    
    coinsNumber += Change // 25
    Change %= 25
    
    coinsNumber += Change // 10
    Change %= 10
    
    coinsNumber += Change // 5
    Change %= 5
    
    coinsNumber += Change
    
    print("{}".format(coinsNumber))
    
if __name__ == "__main__":
    main()