# o código foi retirado do site geeksforgeeks:
# https://www.geeksforgeeks.org/count-number-of-distinct-substring-in-a-string/
 
class TrieNode:
    def __init__(self):
        self.isWord = False
        self.child = [None] * 26
 
def countDistinctSubstring(string):
    head = TrieNode()
 
    count = 0
 
    for i in range(len(string)):
        temp = head
 
        for j in range(i, len(string)):
            # when char not present add it to the trie
            if not temp.child[ord(string[j]) - ord('a')]:
                temp.child[ord(string[j]) - ord('a')] = TrieNode()
                temp.isWord = True
                count += 1
            # move on to the next char
            temp = temp.child[ord(string[j]) - ord('a')]
 
    return count
 
palavra = input()
count = countDistinctSubstring(palavra)
print(count)