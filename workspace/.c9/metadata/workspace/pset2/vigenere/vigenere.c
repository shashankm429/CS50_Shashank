{"filter":false,"title":"vigenere.c","tooltip":"/pset2/vigenere/vigenere.c","undoManager":{"mark":70,"position":70,"stack":[[{"start":{"row":0,"column":0},"end":{"row":1,"column":0},"action":"insert","lines":["",""],"id":1}],[{"start":{"row":0,"column":0},"end":{"row":70,"column":1},"action":"insert","lines":["#include <cs50.h>","#include <stdio.h>","#include <string.h>","#include <ctype.h>","#include <stdlib.h>","","int main(int argc, string argv[])","{","    string plainText;","    // calculates length ","    int keyLength;","    string key;","    // checks for no. of command line arguments","    if (argc != 2)","    {","        printf (\"No command line argument passed \\n\");","        return 1; ","    }","    else","    {","        keyLength = strlen(argv[1]);","        key = argv[1];","        // checks for non-alphabetical characters in key","        for (int i = 0; i < keyLength; i++)","        {","            if (!isalpha(key[i]))","            {","                printf (\"key contains non-alphabetical character\\n\");","                return 1;  ","            }","            else","            {","                if (isupper(key[i]))","                {","                    key[i] = key[i] - 65;","                }","                else if(islower(key[i]))","                {","                    key[i] = key[i] - 97;","                }","            }","        }","    }","    // to get plain text from user","    plainText = GetString();","    // adds key to the plain text","    int j = 0;","    for(int i = 0, n = strlen(plainText); i < n; i++)","    {","        // condition for capital letters","        if (plainText[i] >= 'A' && plainText[i] <= 'Z')","        {","            plainText[i] = (((plainText[i] - 65) + key[j]) % 26) + 65;","            j++;","        }","        else if (plainText[i] >= 'a' && plainText[i] <= 'z')","        {","            // condition for small letters","            plainText[i] = (((plainText[i] - 97) + key[j]) % 26) + 97;","            j++;","        }","        // to loop through key","        if (j == keyLength)","        {","            j = 0;","        }","    }","    printf(\"%s\",plainText);","    printf(\"\\n\");","    return 0; ","}"],"id":2}],[{"start":{"row":9,"column":23},"end":{"row":9,"column":24},"action":"remove","lines":["h"],"id":3}],[{"start":{"row":9,"column":22},"end":{"row":9,"column":23},"action":"remove","lines":["t"],"id":4}],[{"start":{"row":9,"column":21},"end":{"row":9,"column":22},"action":"remove","lines":["g"],"id":5}],[{"start":{"row":9,"column":20},"end":{"row":9,"column":21},"action":"remove","lines":["n"],"id":6}],[{"start":{"row":9,"column":19},"end":{"row":9,"column":20},"action":"remove","lines":["e"],"id":7}],[{"start":{"row":9,"column":18},"end":{"row":9,"column":19},"action":"remove","lines":["l"],"id":8}],[{"start":{"row":9,"column":17},"end":{"row":9,"column":18},"action":"remove","lines":[" "],"id":9}],[{"start":{"row":9,"column":16},"end":{"row":9,"column":17},"action":"remove","lines":["s"],"id":10}],[{"start":{"row":9,"column":15},"end":{"row":9,"column":16},"action":"remove","lines":["e"],"id":11}],[{"start":{"row":9,"column":14},"end":{"row":9,"column":15},"action":"remove","lines":["t"],"id":12}],[{"start":{"row":9,"column":13},"end":{"row":9,"column":14},"action":"remove","lines":["a"],"id":13}],[{"start":{"row":9,"column":12},"end":{"row":9,"column":13},"action":"remove","lines":["l"],"id":14}],[{"start":{"row":9,"column":11},"end":{"row":9,"column":12},"action":"remove","lines":["u"],"id":15}],[{"start":{"row":9,"column":10},"end":{"row":9,"column":11},"action":"remove","lines":["c"],"id":16}],[{"start":{"row":9,"column":9},"end":{"row":9,"column":10},"action":"remove","lines":["l"],"id":17}],[{"start":{"row":9,"column":8},"end":{"row":9,"column":9},"action":"remove","lines":["a"],"id":18}],[{"start":{"row":9,"column":7},"end":{"row":9,"column":8},"action":"remove","lines":["c"],"id":19}],[{"start":{"row":9,"column":6},"end":{"row":9,"column":7},"action":"remove","lines":[" "],"id":20}],[{"start":{"row":9,"column":5},"end":{"row":9,"column":6},"action":"remove","lines":["/"],"id":21}],[{"start":{"row":9,"column":4},"end":{"row":9,"column":5},"action":"remove","lines":["/"],"id":22}],[{"start":{"row":12,"column":4},"end":{"row":12,"column":47},"action":"remove","lines":["// checks for no. of command line arguments"],"id":23}],[{"start":{"row":22,"column":8},"end":{"row":22,"column":56},"action":"remove","lines":["// checks for non-alphabetical characters in key"],"id":24}],[{"start":{"row":43,"column":4},"end":{"row":43,"column":34},"action":"remove","lines":["// to get plain text from user"],"id":25}],[{"start":{"row":45,"column":4},"end":{"row":45,"column":33},"action":"remove","lines":["// adds key to the plain text"],"id":26}],[{"start":{"row":49,"column":8},"end":{"row":49,"column":40},"action":"remove","lines":["// condition for capital letters"],"id":27}],[{"start":{"row":57,"column":12},"end":{"row":57,"column":42},"action":"remove","lines":["// condition for small letters"],"id":28}],[{"start":{"row":61,"column":8},"end":{"row":61,"column":30},"action":"remove","lines":["// to loop through key"],"id":29}],[{"start":{"row":43,"column":4},"end":{"row":43,"column":5},"action":"insert","lines":["p"],"id":30}],[{"start":{"row":43,"column":5},"end":{"row":43,"column":6},"action":"insert","lines":["r"],"id":31}],[{"start":{"row":43,"column":6},"end":{"row":43,"column":7},"action":"insert","lines":["i"],"id":32}],[{"start":{"row":43,"column":7},"end":{"row":43,"column":8},"action":"insert","lines":["n"],"id":33}],[{"start":{"row":43,"column":8},"end":{"row":43,"column":9},"action":"insert","lines":["t"],"id":34}],[{"start":{"row":43,"column":9},"end":{"row":43,"column":10},"action":"insert","lines":["f"],"id":35}],[{"start":{"row":43,"column":10},"end":{"row":43,"column":12},"action":"insert","lines":["()"],"id":36}],[{"start":{"row":43,"column":11},"end":{"row":43,"column":13},"action":"insert","lines":["\"\""],"id":37}],[{"start":{"row":43,"column":12},"end":{"row":43,"column":13},"action":"insert","lines":["p"],"id":38}],[{"start":{"row":43,"column":13},"end":{"row":43,"column":14},"action":"insert","lines":["l"],"id":39}],[{"start":{"row":43,"column":14},"end":{"row":43,"column":15},"action":"insert","lines":["a"],"id":40}],[{"start":{"row":43,"column":15},"end":{"row":43,"column":16},"action":"insert","lines":["i"],"id":41}],[{"start":{"row":43,"column":16},"end":{"row":43,"column":17},"action":"insert","lines":["n"],"id":42}],[{"start":{"row":43,"column":17},"end":{"row":43,"column":18},"action":"insert","lines":["t"],"id":43}],[{"start":{"row":43,"column":18},"end":{"row":43,"column":19},"action":"insert","lines":["e"],"id":44}],[{"start":{"row":43,"column":19},"end":{"row":43,"column":20},"action":"insert","lines":["x"],"id":45}],[{"start":{"row":43,"column":20},"end":{"row":43,"column":21},"action":"insert","lines":["t"],"id":46}],[{"start":{"row":43,"column":21},"end":{"row":43,"column":22},"action":"insert","lines":[":"],"id":47}],[{"start":{"row":43,"column":22},"end":{"row":43,"column":23},"action":"insert","lines":[" "],"id":48}],[{"start":{"row":43,"column":25},"end":{"row":43,"column":26},"action":"insert","lines":[";"],"id":49}],[{"start":{"row":67,"column":12},"end":{"row":67,"column":13},"action":"insert","lines":["c"],"id":50}],[{"start":{"row":67,"column":13},"end":{"row":67,"column":14},"action":"insert","lines":["i"],"id":51}],[{"start":{"row":67,"column":14},"end":{"row":67,"column":15},"action":"insert","lines":["p"],"id":52}],[{"start":{"row":67,"column":15},"end":{"row":67,"column":16},"action":"insert","lines":["h"],"id":53}],[{"start":{"row":67,"column":16},"end":{"row":67,"column":17},"action":"insert","lines":["e"],"id":54}],[{"start":{"row":67,"column":17},"end":{"row":67,"column":18},"action":"insert","lines":["r"],"id":55}],[{"start":{"row":67,"column":18},"end":{"row":67,"column":19},"action":"insert","lines":["t"],"id":56}],[{"start":{"row":67,"column":19},"end":{"row":67,"column":20},"action":"insert","lines":["e"],"id":57}],[{"start":{"row":67,"column":20},"end":{"row":67,"column":21},"action":"insert","lines":["x"],"id":58}],[{"start":{"row":67,"column":21},"end":{"row":67,"column":22},"action":"insert","lines":["t"],"id":59}],[{"start":{"row":67,"column":22},"end":{"row":67,"column":23},"action":"insert","lines":[":"],"id":60}],[{"start":{"row":67,"column":23},"end":{"row":67,"column":24},"action":"insert","lines":[" "],"id":61}],[{"start":{"row":67,"column":24},"end":{"row":67,"column":25},"action":"insert","lines":["m"],"id":62}],[{"start":{"row":67,"column":25},"end":{"row":67,"column":26},"action":"insert","lines":["a"],"id":63}],[{"start":{"row":67,"column":26},"end":{"row":67,"column":27},"action":"insert","lines":["k"],"id":64}],[{"start":{"row":67,"column":27},"end":{"row":67,"column":28},"action":"insert","lines":[" "],"id":65}],[{"start":{"row":67,"column":28},"end":{"row":67,"column":29},"action":"insert","lines":["e"],"id":66}],[{"start":{"row":67,"column":28},"end":{"row":67,"column":29},"action":"remove","lines":["e"],"id":67}],[{"start":{"row":67,"column":27},"end":{"row":67,"column":28},"action":"remove","lines":[" "],"id":68}],[{"start":{"row":67,"column":26},"end":{"row":67,"column":27},"action":"remove","lines":["k"],"id":69}],[{"start":{"row":67,"column":25},"end":{"row":67,"column":26},"action":"remove","lines":["a"],"id":70}],[{"start":{"row":67,"column":24},"end":{"row":67,"column":25},"action":"remove","lines":["m"],"id":71}]]},"ace":{"folds":[],"scrolltop":699,"scrollleft":0,"selection":{"start":{"row":67,"column":24},"end":{"row":67,"column":24},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":42,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1495634540481,"hash":"e57d4d48dafd45310033d31a65f88df4c34df89f"}