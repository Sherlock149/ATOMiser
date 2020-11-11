#!/usr/bin/env python
# coding: utf-8

# In[1]:


from keras.datasets import cifar10


# In[2]:


import matplotlib.pyplot as plt


# In[9]:


(train_X,train_Y),(test_X,test_Y) = cifar10.load_data()


# In[10]:


plt.figure(figsize=(20,10))


for i in range(6):
    plt.subplot(330+1+i)
    plt.imshow(train_X[i])
plt.show()


# In[13]:


from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Dropout
from keras.layers import Flatten
from keras.constraints import maxnorm
from keras.optimizers import SGD
from keras.layers.convolutional import Conv2D
from keras.layers.convolutional import MaxPooling2D
from keras.utils import np_utils


# In[14]:


train_x=train_X.astype('float32')
test_X=test_X.astype('float32') 
train_X=train_X/255.0
test_X=test_X/255.0


# In[15]:


train_Y=np_utils.to_categorical(train_Y)
test_Y=np_utils.to_categorical(test_Y)
num_classes=test_Y.shape[1]


# In[16]:


model=Sequential()
model.add(Conv2D(32,(3,3),input_shape=(32,32,3),padding='same',activation='relu',kernel_constraint=maxnorm(3)))
model.add(Dropout(0.2))
model.add(Conv2D(32,(3,3),activation='relu',padding='same',kernel_constraint=maxnorm(3)))
model.add(MaxPooling2D(pool_size=(2,2)))
model.add(Flatten())
model.add(Dense(512,activation='relu',kernel_constraint=maxnorm(3)))
model.add(Dropout(0.5))
model.add(Dense(num_classes, activation='softmax'))

# In[18]:


sgd=SGD(lr=0.01,momentum=0.9,decay=(0.01/25),nesterov=False) 
model.compile(loss='categorical_crossentropy',
  optimizer=sgd,
  metrics=['accuracy'])


# In[19]:


model.summary()


# In[20]:


model.fit(train_X,train_Y,
    validation_data=(test_X,test_Y),
    epochs=20,batch_size=32)


# In[21]:


_,acc=model.evaluate(test_X,test_Y)
print(acc*100)

model.save("model1_cifar_20epoch.h5")





