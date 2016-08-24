/**
 * Ata Niyazov 130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Insan kaynaklari ve kariyer bilgi sistemi
 */

/**
 * spider.c - Agaca ekleme, silme, gezme ve filtreleme islem fonksiyonlari
 */

#include "headfirst.h"

/**
 * Ikili arama agacina kisi dugumunu ekleme fonksiyonu
 */

void Insert_Node(struct PersonaNode ** RootNode, struct PersonaNode * Node) {
    if((*RootNode) == NULL) {
        (*RootNode) = Node;
    } else {
        int pathfinder = strcmp((*RootNode)->name, Node->name);
        if(pathfinder > 0) {
            Insert_Node(&((*RootNode)->left), Node);
        } else if(pathfinder < 0) {
            Insert_Node(&((*RootNode)->right), Node);
        } else {
            printf("HATALI ISLEM: Ayni arama degerli dugum agaca konmaz!\n");
        }
    }
}

/**
 * Traverse
 */

/**
 * PRE-ORDER
 */

void Pre_Order(struct PersonaNode * RootNode) {
    if(RootNode != NULL) {
        printf("│%4d│%26s│\n",RootNode->id,RootNode->name);
        Pre_Order(RootNode->left);
        Pre_Order(RootNode->right);
    }
}

/**
 * IN-ORDER
 */

void In_Order(struct PersonaNode * RootNode) {
    if(RootNode != NULL) {
        In_Order(RootNode->left);
        printf("│%4d│%26s│\n",RootNode->id,RootNode->name);
        In_Order(RootNode->right);
    }
}

/**
 * POST-ORDER
 */

void Post_Order(struct PersonaNode * RootNode) {
    if(RootNode != NULL) {
        Post_Order(RootNode->left);
        Post_Order(RootNode->right);
        printf("│%4d│%26s│\n",RootNode->id,RootNode->name);
    }
}

/**
 *
 */

void Search_Node(struct PersonaNode * RootNode, char * key) {
    if(RootNode != NULL) {
        int pathfinder = strcmp(RootNode->name, key);
        if(pathfinder == 0) {
            printPersonaNode(RootNode);
        } else if(pathfinder > 0) {
            Search_Node((RootNode->left), key);
        } else if(pathfinder < 0) {
            Search_Node((RootNode->right), key);
        }
    } else {
        printf("Aranan %s bulunamadi\n",key);
    }
}

/**
 * Parametre olarak alinan "Target" dugumun kisiye ait oldugu verileri,
 * egitim durumu ve mezun oldugu veya devam ettigi okullarin bilgilerini,
 * is deneyimi ve calistigi isyerinin bilgilerini silerek "Source" dugumunun
 * bilgilerini kopyalama yapan fonksiyon
 */

void PersonaCpy(struct PersonaNode * Target, struct PersonaNode * Source) {

    if(Source != NULL) {

        Target->institute = Destroy_Edu_List(Target->institute);
        Target->workplace = Destroy_Work_List(Target->workplace);

        Target->id = Source->id;

        strcpy(Target->name, Source->name);
        strcpy(Target->address, Source->address);
        strcpy(Target->phone, Source->phone);
        strcpy(Target->email, Source->email);

        Target->dob = Source->dob;

        strcpy(Target->lingo, Source->lingo);
        strcpy(Target->driver, Source->driver);

        EduCpy(&(Target->institute), Source->institute);
        WorkCpy(&(Target->workplace), Source->workplace);
    }
}

/**
 * Parametre olarak alinan "Target" dugumun kisiye ait oldugu
 * egitim durumu ve mezun oldugu veya devam ettigi okullarin
 * bilgilerini silerek "Source" dugumlerinin bilgilerini
 * kopyalama yapan fonksiyon
 */

void EduCpy(struct edu_status ** Target, struct edu_status * Source) {
    (*Target) = Destroy_Edu_List(*Target);
    if(Source != NULL) {
        struct edu_status * NewEdu = malloc(sizeof(struct edu_status));

        NewEdu->edu_value = Source->edu_value;
        strcpy(NewEdu->edu_name, Source->edu_name);
        strcpy(NewEdu->degree, Source->degree);
        strcpy(NewEdu->department, Source->department);
        NewEdu->started = Source->started;
        NewEdu->graduated = Source->graduated;
        NewEdu->average = Source->average;

        NewEdu->next = NULL;

        (*Target) = NewEdu;

        struct edu_status * tempSource = Source->next;

        while(tempSource != NULL) {
            NewEdu->next = malloc(sizeof(struct edu_status));
            NewEdu = NewEdu->next;

            NewEdu->edu_value = tempSource->edu_value;
            strcpy(NewEdu->edu_name, tempSource->edu_name);
            strcpy(NewEdu->degree, tempSource->degree);
            strcpy(NewEdu->department, tempSource->department);
            NewEdu->started = tempSource->started;
            NewEdu->graduated = tempSource->graduated;
            NewEdu->average = tempSource->average;

            NewEdu->next = NULL;

            tempSource = tempSource->next;
        }
    }
}

/**
 * Parametre olarak alinan "Target" dugumun kisiye ait oldugu
 * is deneyimi ve calistigi isyerinin bilgilerini silerek "Source"
 * dugumlerinin bilgilerini kopyalama yapan fonksiyon
 */

void WorkCpy(struct work_exper ** Target, struct work_exper * Source) {
    (*Target) = Destroy_Work_List(*Target);
    if(Source != NULL) {
        struct work_exper * NewWork = malloc(sizeof(struct work_exper));

        strcpy(NewWork->work_name, Source->work_name);
        strcpy(NewWork->work_address, Source->work_address);
        strcpy(NewWork->position, Source->position);

        NewWork->duration = Source->duration;

        NewWork->next = NULL;

        (*Target) = NewWork;

        struct work_exper * tempSource = Source->next;

        while(tempSource != NULL) {
            NewWork->next = malloc(sizeof(struct work_exper));
            NewWork = NewWork->next;

            strcpy(NewWork->work_name, tempSource->work_name);
            strcpy(NewWork->work_address, tempSource->work_address);
            strcpy(NewWork->position, tempSource->position);

            NewWork->duration = tempSource->duration;

            NewWork->next = NULL;

            tempSource = tempSource->next;
        }
    }
}

/**
 * Ikili arama agacinin en kucuk degerli dugumunu bulan ve adresini
 * geri donduren fonksiyon
 * Not: Bu fonksiyon ikili agactan silme islemi icin gereklidir
 */

struct PersonaNode * FindMinNode(struct PersonaNode * RootNode) {
    struct PersonaNode * currentNode = RootNode;

    while(currentNode->left != NULL) {
        currentNode = currentNode->left;
    }
    return currentNode;
}

/**
 * Ikili arama agacindan parametre olarak alinan "target" degerine esit dugumu
 * silme fonksiyonu
 */

struct PersonaNode * Delete_Node(struct PersonaNode * RootNode, char * target) {
    if(RootNode == NULL) {
        return RootNode;
    } else {
        int pathfinder = strcmp(str_tolower(RootNode->name),str_tolower(target));
        if(pathfinder > 0) {
            RootNode->left = Delete_Node(RootNode->left, target);
        } else if(pathfinder < 0) {
            RootNode->right = Delete_Node(RootNode->right, target);
        } else if(pathfinder == 0) {
            // Case 1:  No child
            if(RootNode->left == NULL && RootNode->right == NULL) {
                RootNode->institute = Destroy_Edu_List(RootNode->institute);
                RootNode->workplace = Destroy_Work_List(RootNode->workplace);

                free(RootNode);
                RootNode = NULL;
            }
            // Case 2: One child
            else if(RootNode->left == NULL) {
                struct PersonaNode *temp = RootNode;
                RootNode = RootNode->right;

                temp->institute = Destroy_Edu_List(temp->institute);
                temp->workplace = Destroy_Work_List(temp->workplace);

                free(temp);
            } else if(RootNode->right == NULL) {
                struct PersonaNode *temp = RootNode;
                RootNode = RootNode->left;

                temp->institute = Destroy_Edu_List(temp->institute);
                temp->workplace = Destroy_Work_List(temp->workplace);

                free(temp);
            }
            // Case 3: 2 children
            else {
                struct PersonaNode *temp = FindMinNode(RootNode->right);
                PersonaCpy(RootNode,temp);
                RootNode->right = Delete_Node(RootNode->right,temp->name);
            }

        }
        return RootNode;
    }
}

/**
 * Parametre olarak alinan dugumun kisiye ait oldugu egitim durumu ve
 * mezun oldugu veya devam ettigi okullarin bilgilerini saklan
 * bagli liste dugumlerini bellekten silen ve geri "NULL" donderen
 * fonksiyon
 */

struct edu_status * Destroy_Edu_List(struct edu_status * institute) {
    if(institute == NULL) {
    } else {
        institute->next = Destroy_Edu_List(institute->next);
        free(institute);
        institute = NULL;
    }
    return institute;
}

/**
 * Parametre olarak alinan dugumun kisiye ait oldugu is deneyimi ve
 * calistigi isyerinin bilgilerini saklan bagli liste dugumlerini
 * bellekten silen ve geri "NULL" donderen fonksiyon
 */

struct work_exper * Destroy_Work_List(struct work_exper * workplace) {
    if(workplace == NULL) {
    } else {
        workplace->next = Destroy_Work_List(workplace->next);
        free(workplace);
        workplace = NULL;
    }
    return workplace;
}

/**
 * Ikili arama agacinin dugumlerini bellekten silme fonksiyonu
 */

void Destroy_Tree(struct PersonaNode ** RootNode) {
    if(RootNode != NULL) {
        Destroy_Tree(&((*RootNode)->left));
        Destroy_Tree(&((*RootNode)->right));
        (*RootNode)->institute = Destroy_Edu_List((*RootNode)->institute);
        (*RootNode)->workplace = Destroy_Work_List((*RootNode)->workplace);
        free(*RootNode);
        *RootNode = NULL;
    }
}

/**
 *
 */

int Max_Depth(struct PersonaNode * RootNode) {
    if (RootNode == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = Max_Depth(RootNode->left);
        int rDepth = Max_Depth(RootNode->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}


/**
 * Bagli liste fonksiyonlari
 * LINKED LIST
 */

/**
 * Ikili arama agacinin kisi bilgiler dugumlerini bagli liste doken fonksiyon
 */

void PersonaTree2LinkList(struct PersonaLinkList ** head, struct PersonaNode * RootNode) {
    if(RootNode != NULL) {
        PersonaTree2LinkList(head, RootNode->left);
        AddPersonaLinkList(head, RootNode);
        PersonaTree2LinkList(head, RootNode->right);
    }
}

/**
 * Kisi bilgiler bagli listesine eleman ekleme fonksiyonu
 */

void AddPersonaLinkList(struct PersonaLinkList ** head, struct PersonaNode * Node) {
    struct PersonaLinkList * NewLink = malloc(sizeof(struct PersonaLinkList));

    NewLink->Persona = Node;
    NewLink->next = NULL;

    if((*head) == NULL) {
        (*head) = NewLink;
    } else {
        struct PersonaLinkList * tail = (*head);

        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = NewLink;
    }
}

/**
 * Kisi bilgiler bagli listesini ekrana yazan fonksiyon
 */

void PrintLinkList(struct PersonaLinkList * head) {
    struct PersonaLinkList * tail = head;

    while(tail != NULL) {
        printPersonaNode(tail->Persona);
        printf("\n");
        tail = tail->next;
    }
}

/**
 * Kisi bilgiler bagli listesinden "target" degerli elemani silme fonksiyonu
 */

struct PersonaLinkList * DeletePersonaLinkList(struct PersonaLinkList * head, char * target) {
    if(head == NULL) {
        return head;
    } else {
        if(strcmp(head->Persona->name, target) == 0) {
            struct PersonaLinkList * assassin = head;
            head = head->next;
            free(assassin);
        } else {
            head->next = DeletePersonaLinkList(head->next, target);
        }
        return head;
    }
}

/**
 * Kisi bilgiler bagli listesini ID degerine gore kabarcikli siralama
 * (bubble sort) yapan fonksiyon
 */

struct PersonaLinkList * ID_SortPersonaLinkList(struct PersonaLinkList * head) {

    struct PersonaLinkList * tmpPtr = head;
    struct PersonaLinkList * tmpNxt = head->next;

    struct PersonaNode * temp = NULL;

    while(tmpNxt != NULL) {
        while(tmpNxt != tmpPtr) {
            if(tmpPtr->Persona->id > tmpNxt->Persona->id) {
                temp = tmpPtr->Persona;
                tmpPtr->Persona = tmpNxt->Persona;
                tmpNxt->Persona = temp;
            }
            tmpPtr = tmpPtr->next;
        }
        tmpPtr = head;
        tmpNxt = tmpNxt->next;
    }
    return tmpPtr ;
}

/**
 * Kisi bilgiler bagli listesinin elemanlarini bellekten silen fonksiyon
 */

void DestroyPersonaLinkList(struct PersonaLinkList ** head) {
    if((*head) != NULL) {
        DestroyPersonaLinkList(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}

/**
 * Ikili arama agacinda kisi sayisini geri donderen fonksiyon
 */

int PersonaCounter(struct PersonaNode * RootNode) {
    int counter = 0;
    if(RootNode != NULL) {
        //printNode(RootNode);
        counter++;
        counter += PersonaCounter(RootNode->left);
        counter += PersonaCounter(RootNode->right);
    }
    return counter;
}

/**
 * Projede kullanilmadik fonksiyonlar
 */

/**
 * Parametre olarak alinan ikili arama agacinin dugumunun
 * yaprak dugum olup olmadigini kontrol eden fonksiyon
 */

bool Is_Leaf(struct PersonaNode * Node) {
    if(Node != NULL) {
        if(Node->left == NULL && Node->right == NULL) {
            return true;
        } else {
            return false;
        }
    } else {
        printf("Dugum mevcut degil!\n");
        return false;
    }
}

/**
 * Ikili arama agacinda kisi sayisini geri donderen fonksiyon
 */

int PersonaLinkCounter(struct PersonaLinkList * head) {
    struct PersonaLinkList * tail = head;

    int counter = 0;

    while(tail != NULL) {
        counter++;
        tail = tail->next;
    }
    return counter;
}
