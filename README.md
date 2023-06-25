# king_chess

CZ:
Ze souboru sachovnice.txt načtěte popis šachovnice a určete pro ni délku nejkratší cesty králem. Výsledek vypište na standardní výstup (terminál). Šachovnice je popsána tak, že na prvních dvou řádcích jsou kladná celá čísla x a y určující počet řádků, resp. sloupců šachovnice. Následuje x řádků o y znacích. Každý znak je:

 tečka, což značí pole, na které smíme vstoupit,
 X (velké), což znační zakázané pole,
 S (taktéž velké), startovní pole,
 C (opět velké), cílové pole.
 Pokud příslušná cesta neexistuje, vypište -1.

 EN:
 Read the description of a chessboard from the file "sachovnice.txt" and determine the length of the shortest path for a king on that chessboard. Print the result to the standard output (terminal). The chessboard is described as follows: the first two lines of the file contain positive integers x and y, which specify the number of rows and columns of the chessboard, respectively. This is followed by x lines of y characters. Each character represents:

A period (".") indicates a square that the king can enter.
An uppercase "X" represents a forbidden square.
An uppercase "S" represents the starting square.
An uppercase "C" represents the target square.
If there is no valid path, print -1.
