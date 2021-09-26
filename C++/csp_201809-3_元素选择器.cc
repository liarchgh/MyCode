#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int max_n = 100+5, max_m = 10 + 5, max_line=80+8;
int n, m, res[max_n], resLen;

struct Node{
    char type[max_line], id[max_line];
    int level, lineNum;
    Node* father;
    Node(){
        type[0]='\0';
        id[0]='\0';
        level = 0;
        lineNum = 0;
        father = NULL;
    }

    bool Search(Node* node){
        // printf("%s+++++%s\n", id, node->id);
        bool ans = true;
        ans = ans && (strlen(node->type)>0?strcmp(type, node->type)==0:true);
        ans = ans && (strlen(node->id)>0?strcmp(id, node->id)==0:true);
        ans = ans && (node->father!=NULL?father!=NULL&&father->Search(node->father):true);
        return ans;
    }
}nodes[max_n];

void OutAllNodes(){
    puts("==============");
    for(int i = 0; i < n; ++i){
        printf("%s %s %d\n", nodes[i].type, nodes[i].id, nodes[i].level);
    }
    puts("==============");
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d\n", &n, &m);
    char line[max_line];
    for(int i = 0,lv,typeEnd,len,ids,ide; i < n; ++i){
        // prepare
        gets(line);
        len = strlen(line);
        for(int ii = 0; ii < len; ++ii){
            if(line[ii] >= 'A' && line[ii] <= 'Z'){
                line[ii] = 'a'+line[ii]-'A';
            }
            if(line[ii]=='#'){
                while(ii < len && line[ii]!=' '){
                    ++ii;
                }
            }
        }
        Node& node = nodes[i];

        // lineNum
        node.lineNum = i+1;

        // level
        for(lv = 0; line[lv]=='.'; ++lv){}
        lv >>= 1;
        node.level = lv;

        // type
        for (typeEnd = lv<<1; typeEnd<len && line[typeEnd]!=' '; ++typeEnd){
            node.type[typeEnd-(lv<<1)] = line[typeEnd];
        }
        node.type[typeEnd-(lv<<1)] = '\0';

        // father, head node's father is NULL
        if(i > 0){
            Node* fa = &nodes[i-1];
            while(fa!=NULL && fa->level >= lv){
                fa = fa->father;
            }
            node.father = fa;
        }

        // id
        if(typeEnd < len){
            ids = typeEnd + 2;
            for(ide=ids; ide < len && line[ide]!=' '; ++ide){
                node.id[ide-ids] = line[ide];
            }
        }

#ifndef ONLINE_JUDGE
        // OutAllNodes();
        // printf("%d\n", i);
#endif
    }

    for(int i = 0,len; i < m; ++i){
        gets(line);
        len = strlen(line);

        // change upper character to lower
        for(int ii = 0; ii < len; ++ii){
            if(line[ii] >= 'A' && line[ii] <= 'Z'){
                line[ii] = 'a'+line[ii]-'A';
            }
            if(line[ii]=='#'){
                while(ii < len && line[ii]!=' '){
                    ++ii;
                }
            }
        }

        string ps(line);
        Node* node = NULL;
        while(ps.length() > 0){
            Node* newNode = new Node();
            newNode->father = node;
            node = newNode;

            if(ps[0]!='#'){
                size_t pos = ps.find(" ");
                // printf("find at %d\n", pos);
                if(pos == ps.npos){
                    // printf("ther are same\n");
                    pos = ps.length();
                    // printf("ps's length is %d\n",ps.length());
                }
                for(int i = 0; i < pos; ++i){
                    node->type[i] = ps[i];
                }
                node->type[pos] = '\0';
                if(pos >= ps.length()){break;}

                if(ps[pos+2]=='#'){
                    ps = ps.substr(pos+2, ps.length());
                }
                else{
                    ps = ps.substr(pos+1, ps.length());
                }
            }

            // id
            int pos = 0;
            if(ps[pos]=='#'){
                ++pos;
                int ids = pos;
                for(; pos<ps.length() && ps[pos]!=' '; ++pos){
                    node->id[pos-ids]=ps[pos];
                }
                node->id[pos-ids]='\0';
                if(ps[pos]==' '){
                    ++pos;
                }
            }

            ps = ps.substr(pos, ps.length());
        }

        resLen = 0;
        for(int i = 0; i < n; ++i){
            if(nodes[i].Search(node)){
                res[resLen++] = i+1;
            }
        }

        printf("%d", resLen);
        if(resLen > 0){
            putchar(' ');
            for(int i = 0; i < resLen-1; ++i){
                printf("%d ", res[i]);
            }
            printf("%d\n", res[resLen-1]);
        }
        else{
            putchar('\n');
        }
    }
    return 0;
}