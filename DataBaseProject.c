#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define string char*
#define true 1
#define false 0
#define and &&
#define or ||
typedef struct Attributes Attributes;
typedef struct Entity Entity;
typedef struct StrongEntity StrongEntity;
typedef struct WeakEntity WeakEntity;
struct Attributes{
    string name;
    string datatype;
};
struct Entity{
    string name;
    Attributes* attributes;
    char key;
    string id;
    size_t attrCount;
    string relation;
};
struct StrongEntity{
    string name;
    string key;
    size_t attrCount;
    Attributes* attributes;
    char relation;
};
struct WeakEntity{
    string name;
    StrongEntity father;
    size_t attrCount;
    Attributes* attributes;
    char relation;
    string r;
};
string getKey(string attribute){
    // @ f o r e i g n _ k e y ( )
    int size = strlen(attribute) - 1;
    string buffer = (string)malloc(sizeof(char)*35);
    for(int i = 13, j = 0 ; attribute[i] != ')' && i < size; i++, j++) buffer[j] = attribute[i];
    return buffer;
}
typedef struct Pair Pair;
#define stEnt StrongEntity
#define wkEnt WeakEntity
struct Pair{
    stEnt strong[50];
    wkEnt weak[50];
};
int stc, wkc;
Pair phaseOneAndTwo(Entity* entities, const size_t size){
    Pair pair;
    for(int i = 0, j = 0, k = 0 ; i < (int)size ; i++){
        Entity entity = entities[i];
        if(entity.key == 'p'){
            stEnt st;
            st.attrCount = entity.attrCount;
            st.attributes = entity.attributes;
            st.name = entity.name;
            if(entity.name[strlen(entity.name)-1] == 's') st.relation = 'n';
            else st.relation = '1';
            pair.strong[j++] = st;
            stc++;
        }else{
            wkEnt wk;
            wk.attrCount = entity.attrCount;
            wk.attributes = entity.attributes;
            wk.name = entity.name;
            if(entity.name[strlen(entity.name)-1] == 's') wk.relation = 'n';
            else wk.relation = '1';
            wk.r = entity.relation;
            pair.weak[k++] = wk;
            wkc++;
        }
    }
    return pair;
}
Pair getFather(stEnt* st, wkEnt* wk){
    Pair ret;
    for(int i = 0 ; i < wkc ; i++){
        WeakEntity entity = wk[i];
        for(int j = 0 ; j < stc ; j++){
            StrongEntity stE = st[0];
            if(strcmp(entity.r,stE.name)==0){
                wk[i].father = st[j];
                j = stc;
            }
        }
    }
    for(int i = 0 ; i < stc ; i++) ret.strong[i] = st[i];
    for(int i = 0 ; i < wkc ; i++) ret.weak[i] = wk[i];
    return ret;
}
int main(){
    int entitiesCount;
    printf("Ingrese la cantidad de entidades que desea:\n");
    scanf("%d",&entitiesCount);
    Entity* entities = (Entity*)malloc(sizeof(Entity)*entitiesCount);
    for(int i = 0 ; i < entitiesCount ; i++){
        printf("Ingrese el nombre de la entidad %d:\n",i+1);
        string name = (string)malloc(sizeof(char)*35);
        scanf("%s",name);
        getchar();
        printf("Ingrese la cantidad de atributos de la entidad '%s':\n",name);
        int attrCount;
        scanf("%d",&attrCount);
        Entity entity;
        Attributes* attributes = (Attributes*)malloc(sizeof(Attributes)*attrCount+1);
        for(int j = 0 ; j < attrCount ; j++){
            Attributes attribute;
            printf("Ingrese el nombre del atributo %d:\n",j+1);
            string attrName = (string)malloc(sizeof(char)*35);
            scanf("%s",attrName);
            getchar();
            printf("Ingrese el tipo de dato del atributo '%s' (Sin espacios y mayusculas):\nEn caso de ser llave primaria, ingresar: @@primary_key(ClientId)\nEn caso de ser llave foranea ingresar: @@foreign_key(ClientId)\nClientId es un valor de ejemplo\n",attrName);
            string attr = (string)malloc(sizeof(char)*35);
            getchar();
            scanf("%s",attr);
            getchar();
            if(attr[0]=='@'){
                if(attr[1] == 'p') entity.key = 'p';
                else{
                    entity.key = 'f';
                    entity.id = getKey(attr);
                    printf("Ingrese con que tabla esta relacionada (Nombre exacto):\n");
                    string relation = (string)malloc(sizeof(char)*35);
                    scanf("%s",relation);
                    getchar();
                    entity.relation = relation;
                }
            }
            attribute.datatype = attr;
            attribute.name = attrName;
            attributes[j] = attribute;
        }
        entity.name = name;
        entity.attrCount = attrCount;
        entity.attributes = attributes;
        entities[i] = entity;
    }
    Pair pr = phaseOneAndTwo(entities,entitiesCount);
    pr = getFather(pr.strong,pr.weak);
    
}