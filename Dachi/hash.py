'''
Hash Process:
 1.Hash function
 2.Collision resolution

Hash Table Implementations:
 1.Seperate chaining: LinkedList
 2.Linear probing
'''

class HashTableSC:
  '''
  data structure: list of list
  [ [], => a growing linked list, [], [],...]
  hash(key) => hashed_key (0 to M-1)
  get(key) hash(key) = hashed_key => return slots[hashed_key]
  put(key,val) hash(key) = hashed_key => set slots[hashed_key] = val => if non-exist: just put => else: collision resolution => prepend
  '''

  def __init__(self,size):
    self.size = size
    self.slots = []

    for i in range(size):
      self.slots.append([])
      
  def hash(self,key):
    i = key % self.size
    return i

  def get(self,key):
    pass

  def put(self,key,val):
    slot = self.hash(key)
    if key in self.slots[slot]:
        return -1
    else:
        self.slots[slot].append(key)
        return slot

class HashTableLP:
  '''
  keys[]
  vals[]
  hash(key) => hashed_key (0 to m-1)
  put(key,val) => while keys[hashed_key] != None => hashed_key++ => keys[hashed_key] = key, vals[hashed_key] = val
  get(key) =>     while keys[hashed_key] != key and keys[hashed_key] != null => hashed_key++ => return vals[hashed_key]
  resize()
  '''
 
  def __init__(self,):
    pass

  def hash(self,key):
    pass

  def resize(self,newSize):
    pass

  def get(self,key):
    pass

  def put(self,key,val):
    pass

class HashTable:
  def __init__(self):
    self.size = 11
    self.slots = [None] * self.size
    self.data = [None] * self.size

  def hashfunction(self,key,size):
    return key%size

  def rehash(self,oldhash,size):
    return (oldhash+1)%size

  def put(self,key,data):
    hashvalue = self.hashfunction(key,len(self.slots))

    if self.slots[hashvalue] == None:
      self.slots[hashvalue] = key
      self.data[hashvalue] = data
    else:
      if self.slots[hashvalue] == key:
        self.data[hashvalue] = data  #replace
      else:
        nextslot = self.rehash(hashvalue,len(self.slots))
        while self.slots[nextslot] != None and \
                        self.slots[nextslot] != key:
          nextslot = self.rehash(nextslot,len(self.slots))
    
        if self.slots[nextslot] == None:
          self.slots[nextslot]=key
          self.data[nextslot]=data
        else:
          self.data[nextslot] = data #replace

  def get(self,key):
    startslot = self.hashfunction(key,len(self.slots))

    data = None
    stop = False
    found = False
    position = startslot
    while self.slots[position] != None and  \
                         not found and not stop:
       if self.slots[position] == key:
         found = True
         data = self.data[position]
       else:
         position=self.rehash(position,len(self.slots))
         if position == startslot:
             stop = True
    return data

  def __getitem__(self,key):
    return self.get(key)

  def __setitem__(self,key,data):
    self.put(key,data)

####
def main():
  pass

if __name__ == "__main__":
  main()
  


