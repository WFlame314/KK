#include "personlist.h"
#include <QAction>
#include <QIcon>

#include <QDebug>

personList::personList(int a,QListWidget *parent) :
    QListWidget(parent)
{
    account=a;
    setFocusPolicy(Qt::NoFocus);       // 去除item选中时的虚线边框
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
    initMenu();
}

//初始化菜单
void personList::initMenu()
{
    //初始化：
    blankMenu = new QMenu();
    groupMenu = new QMenu();
    personMenu = new QMenu();
    groupNameEdit=new QLineEdit();
    QAction *addGroup = new QAction("添加分组", this);
    QAction *delGroup = new QAction("删除该组", this);
    QAction *rename = new QAction("重命名", this);
    QAction *addBuddy = new QAction("添加好友",this);
    QAction *delBuddy = new QAction("删除好友", this);
    //设置：
    groupNameEdit->setParent(this);  //设置父类
    groupNameEdit->hide(); //设置初始时隐藏
    groupNameEdit->setPlaceholderText("未命名");//设置初始时的内容
    //布局：
    blankMenu->addAction(addGroup);
    groupMenu->addAction(delGroup);
    groupMenu->addAction(rename);
    groupMenu->addAction(addBuddy);
    personMenu->addAction(delBuddy);
    //信息槽：
    connect(groupNameEdit,SIGNAL(editingFinished()),this,SLOT(slotRenameEditFshed()));
    connect(addGroup,SIGNAL(triggered()),this,SLOT(slotAddGroup()));
    connect(delGroup,SIGNAL(triggered()),this,SLOT(slotDelGroup()));
    connect(rename,SIGNAL(triggered()),this,SLOT(slotRename()));
    connect(addBuddy,SIGNAL(triggered()),this,SLOT(slotAddBuddy()));
    connect(delBuddy,SIGNAL(triggered()),this,SLOT(slotDelBuddy()));
}
//鼠标点击事件
void personList::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event); // 如果不调用基类mousePressEvent，item被select会半天不响应,调用父类，让QSS起效，因为QSS基于父类QListWidget，子类就是子窗口，就是最上层窗口，是覆盖在父窗口上的，所以先于父窗口捕获消息
    //防止一种特殊情况：给新item命名、点击其他item或空白处时，指向新item的currentItem被赋予其他item
    if(groupNameEdit->isVisible() && !(groupNameEdit->rect().contains(event->pos())))
    {
        if(groupNameEdit->text()!=NULL)
            currentItem->setText(groupNameEdit->text());
        groupNameEdit->setText("");
        groupNameEdit->hide();
    }
    currentItem = this->itemAt(mapFromGlobal(QCursor::pos()));//鼠标位置的Item，不管右键左键都获取
    if(event->button()==Qt::LeftButton && currentItem!=NULL && currentItem==groupMap.value(currentItem))//如果点击的左键并且是点击的是组
    {
        if(isHideMap.value(currentItem))                                  //如果先前是隐藏，则显示
        {
            foreach(QListWidgetItem* subItem, groupMap.keys(currentItem))//遍历组的对应的项（包括自身和好友）
                if(subItem!=currentItem)                                 //如果是组的话不进行处理
                {
                    subItem->setHidden(false);                            //好友全部显示
                }
            isHideMap.insert(currentItem,false);                          //设置该组为显示状态
            currentItem->setIcon(QIcon(":/bg/image/open.png"));
        }
        else                                                             //否则，先前是显示，则隐藏
        {
            foreach(QListWidgetItem* subItem, groupMap.keys(currentItem))//遍历组的对应的项（包括自身和好友）
                if(subItem!=currentItem)                                 //如果是组的话不进行处理
                {
                    subItem->setHidden(true);                            //好友全部隐藏
                }
             isHideMap.insert(currentItem,true);                          //设置该组为隐藏状态
             currentItem->setIcon(QIcon(":/bg/image/hide.png"));
        }
    }
}

//菜单事件，为了显示菜单，点击鼠标右键响应，鼠标点击事件mousePressEvent优先于contextMenuEvent
void personList::contextMenuEvent(QContextMenuEvent *event)
{
    QListWidget::contextMenuEvent(event);           //调用基类事件
    if(currentItem==NULL)                           //如果点击到的是空白处
    {
        blankMenu->exec(QCursor::pos());
        return;
    }
    if(currentItem==groupMap.value(currentItem))    // 如果点击到的是组
        groupMenu->exec(QCursor::pos());
    else                                            //否则点击到的是好友
        personMenu->exec(QCursor::pos());
}
//添加组
void personList::slotAddGroup()
{
    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/bg/image/hide.png"),"未命名");    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),25));//设置宽度、高度
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    isHideMap.insert(newItem,true);  //设置该组隐藏状态
    groupNameEdit->raise();
    groupNameEdit->setText(tr("未命名")); //设置默认内容
    groupNameEdit->selectAll();        //设置全选
    groupNameEdit->setGeometry(this->visualItemRect(newItem).left()+15,this->visualItemRect(newItem).top()+1,this->visualItemRect(newItem).width(),this->visualItemRect(newItem).height()-2);//出现的位置
    groupNameEdit->show();              //显示
    groupNameEdit->setFocus();          //获取焦点
    currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
}

void personList::AddGroup(QString name,int index)
{
    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/bg/image/hide.png"),name.toUtf8());    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),25));//设置宽度、高度
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    groupindex.insert(index,newItem);
    isHideMap.insert(newItem,true);  //设置该组隐藏状态
    groupNameEdit->raise();
    groupNameEdit->setText(tr(name.toUtf8())); //设置默认内容
    groupNameEdit->selectAll();        //设置全选
    groupNameEdit->setGeometry(this->visualItemRect(newItem).left()+15,this->visualItemRect(newItem).top()+1,this->visualItemRect(newItem).width(),this->visualItemRect(newItem).height()-2);//出现的位置
    //groupNameEdit->show();              //显示
    //groupNameEdit->setFocus();          //获取焦点
    currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
}

void personList::AddFriend(QString name,QString sign,int account,int faccount,int isread,int gindex)
{
    personListBuddy *buddy=new personListBuddy();   //创建一个自己定义的信息类
    friends.insert(faccount,buddy);
    buddy->sign->setFixedSize(this->width()-70,27);
    buddy->account=faccount;
    //qDebug()<<QString("./files/%1/%2.jpg").arg(f).arg(faccount);
    QFile file(QString("./files/%1/faces/%2.jpg").arg(account).arg(faccount));
    if(file.exists())
    {
        buddy->headPath=QString("./files/%1/faces/%2.jpg").arg(account).arg(faccount);         //设置头像路径
    }else
    {
        buddy->headPath="./files/logwin/face.png";         //设置头像路径
    }

    buddy->name->setText(name.toUtf8());                  //设置用户名
    QString temp="";
    while(!sign.isEmpty())
    {
        if(sign[0]!='\n')
        {
            temp+=sign[0];
        }
        sign.remove(0,1);
    }
    buddy->sign->setText(temp.toUtf8());   //显示最后一次聊天记录
    buddy->settips();   //设置聊天提示
    buddy->setread(isread);
    currentItem = groupindex.value(gindex);
    QList<QListWidgetItem*> tem = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    this->insertItem(row(currentItem)+tem.count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为好友，value为组
    if(isHideMap.value(currentItem))          //如果该组是隐藏，则加进去的好友设置为隐藏
        newItem->setHidden(true);
    else                                      //否则，该好友设置为显示
        newItem->setHidden(false);
    connect(buddy,SIGNAL(doubleclick(int)),this,SLOT(clickfriend(int)));
}

void personList::clickfriend(int a)
{
    qDebug()<<a<<"clicked";
    emit openchat(a);
}

void personList::newmessage(int facc, QString wo, int isread)
{
    if(friends.find(facc)!=friends.end())
    {
        friends.value(facc)->newmessage(wo,isread);
    }
}


//删除组
void personList::slotDelGroup()
{
    foreach(QListWidgetItem* item, groupMap.keys(currentItem))  //遍历该组的所有好友和自身的组
    {
        groupMap.remove(item);   //移除
        delete item;   //删除
    }
    isHideMap.remove(currentItem); //移除
}
//重命名
void personList::slotRename()
{
    groupNameEdit->raise();
    groupNameEdit->setGeometry(this->visualItemRect(currentItem).left()+15,this->visualItemRect(currentItem).top()+1,this->visualItemRect(currentItem).width(),this->visualItemRect(currentItem).height()-2);//出现的位置
    groupNameEdit->setText(currentItem->text());   //获取该组名内容
    groupNameEdit->show();                        //显示
    groupNameEdit->selectAll();                   //全选
    groupNameEdit->setFocus();                        //获取焦点
}
//添加好友，主要是为了测试功能，实际工程里可以改成动态读取数据库进行添加好友
void personList::slotAddBuddy()
{
    personListBuddy *buddy=new personListBuddy();   //创建一个自己定义的信息类
    buddy->headPath=":/head";                          //设置头像路径
    buddy->name->setText("好友");                  //设置用户名
    buddy->sign->setText("测试测试测试测试");   //设置个性签名
    QList<QListWidgetItem*> tem = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    this->insertItem(row(currentItem)+tem.count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为好友，value为组
    if(isHideMap.value(currentItem))          //如果该组是隐藏，则加进去的好友设置为隐藏
        newItem->setHidden(true);
    else                                      //否则，该好友设置为显示
        newItem->setHidden(false);


}
//删除好友
void personList::slotDelBuddy()
{
    groupMap.remove(currentItem);  //移除该好友
    delete currentItem;            //删除
}
//重命名完成
void personList::slotRenameEditFshed()
{
    if(groupNameEdit->text()!=NULL)      //如果重命名编辑框不为空
        currentItem->setText(groupNameEdit->text());  //更新组名
    groupNameEdit->setText("");
    groupNameEdit->hide();  //隐藏重命名编辑框
}
