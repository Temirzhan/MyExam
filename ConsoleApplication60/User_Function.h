#pragma once
char PrintPocition(Pocition *PocitionBase, User_table *User_base, int *user_pocition, const int sort);
void Sort_Base(Pocition *PocitionBase, const int counter_struct, const int counter_pocition, const int sort);
char User_Order(User_table *User_base, int *user_pocition, User_table *User_order, int *user_pocition_order);
char User_Basket(User_table *User_base, int *user_pocition);
char User_Base_order(User_table *User_base, int *user_pocition_order);
void CloseBase(User_table *Base_User_base, int *use_pocition_base, User_table *Base_User, int *user_pocition, FILE *ptUser, char * User_Base_Folder, char * folder_user);