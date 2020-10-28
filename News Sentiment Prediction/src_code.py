#!/usr/bin/env python
# coding: utf-8

# In[1]:


import nltk;


# In[2]:


from textblob import TextBlob
import pandas as pd


# In[10]:


df=pd.read_csv('train_file.csv', encoding = "ISO-8859-1")


# In[11]:


train = df


# In[12]:


# Removing punctuations
data=train.iloc[:,1:4]
data.replace("[^a-zA-Z]"," ",regex=True, inplace=True)

# Renaming column names for ease of access
list1= [i for i in range(3)]
new_Index=[str(i) for i in list1]
data.columns= new_Index
data.head(5)


# In[13]:


# Convertng headlines to lower case
for index in new_Index:
    data[index]=data[index].str.lower()
data.head(1)


# In[14]:


title = []
for row in range(0,len(data.index)):
    title.append(''.join(str(x) for x in data.iloc[row,0]))


headline = []
for row in range(0,len(data.index)):
    headline.append(''.join(str(x) for x in data.iloc[row,1]))


df=pd.read_csv('test_file.csv', encoding = "ISO-8859-1")


# In[41]:


test = df


# In[42]:


# Removing punctuations
data=test.iloc[:,1:4]
data.replace("[^a-zA-Z]"," ",regex=True, inplace=True)

# Renaming column names for ease of access
list1= [i for i in range(3)]
new_Index=[str(i) for i in list1]
data.columns= new_Index
data.head(5)


# In[43]:


# Convertng headlines to lower case
for index in new_Index:
    data[index]=data[index].str.lower()
data.head(1)


# In[44]:


title = []
for row in range(0,len(data.index)):
    title.append(''.join(str(x) for x in data.iloc[row,0]))


# In[48]:
headline = []
for row in range(0,len(data.index)):
    headline.append(''.join(str(x) for x in data.iloc[row,1]))


headsent = []
for i in range(0,len(data.index)):
    analysis = TextBlob(headline[i])
    headsent.insert(i,analysis.sentiment.polarity)


titlesent = []
for i in range(0,len(data.index)):
    abc = TextBlob(title[i])
    titlesent.insert(i,abc.sentiment.polarity)

df['SentimentTitle'] = titlesent


# In[68]:


df['SentimentHeadline'] = headsent

df.head(7)


# In[72]:


df.to_csv(r'C:\Octave\Machine Learning\dataset\test.csv', index = False)


# In[ ]:
