struct Trie {
    Trie* next[10];
    bool isEnd = 0;

    Trie() {
        fill(next, next+10, (Trie*)NULL);
    }

    ~Trie() {
    //    cout<<"Destructor\n";
        for (int i=0; i<10; ++i) {
            if (next[i] !=NULL) {
                delete next[i];
            }
            next[i]=NULL;
        }
    }

    void insert(string&& word) {
        Trie* Node=this;
        for(char c: word){
            int i=c-'0';
            if(Node->next[i]==NULL)
                Node->next[i]=new Trie();
            Node=Node->next[i];
        }
        Node->isEnd=1;
    }
    
    int commonPrefix(string&& s) {
        Trie* Node = this;
        int len=0;
        for(char c : s){
            int i = c - '0';
            if(Node->next[i]==NULL) return len;
            Node = Node->next[i];
            len++;
        }
        return len;
        
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie=Trie();
        for (int x: arr2)
            trie.insert(to_string(x));
        int maxLen=0;
        for (int x: arr1)
            maxLen=max(maxLen, trie.commonPrefix(to_string(x)));
        return maxLen;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();