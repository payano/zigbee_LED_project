#include "Message.h"

namespace MessagePkg {

MessageBox::MessageBox(int size):
    mMessages(new Message[size]),
    mTotalSize(size),
    mUsed(0){

}
MessageBox::~MessageBox(){
  delete mMessages;
}

void MessageBox::putMessage(Message* message){
  // if there is some place left, put message last in queue.
  // otherwise discard message
  if(mUsed > mTotalSize){
    // Copy the message
    mMessages[mUsed] = *message;
    ++mUsed;
  }

}
void MessageBox::getMessage(Message* message){
  // take the first message and move all message one step to the left:
  if(mUsed > 0){
    *message = mMessages[0];
    //i = 0 must exist
    for(int i = 1; i < mUsed;++i){
      mMessages[i-1] = mMessages[i];
    }
    --mUsed;
  }
}

bool MessageBox::empty(){return mUsed == 0 ? true:false;}
bool MessageBox::full(){return mUsed == mTotalSize ? true:false;}
int MessageBox::maxSize(){return mTotalSize;}
int MessageBox::usedSize(){return mUsed;}

}
