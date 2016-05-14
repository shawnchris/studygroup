import time
import sys
import random

def swap(array,i,j):
  array[i],array[j]=array[j],array[i]

def print_array(array):
  for i in range(len(array)):
    sys.stdout.write(str(array[i])+" ")
    if ( i and (i % 10 == 0)):
      print ""
  print ""

def is_sorted(array):
  for i in range(1,len(array)):
    if( array[i] < array[i-1] ):
      return False
  return True

def selection_sort(array):
  # Idea: For each loop, find the min value and put it on loop begining position
  # Run time is insensitive to input size, always O(n^2)
  size = len(array)
  for i in range(size-1):
    minIdx = i
    for j in range(i+1,size):
      if array[j] < array[minIdx]:
        minIdx = j
    swap(array,i,minIdx)

def insertion_sort(array):
  # Idea: keep array sorted by incrementing the length of subarray
  # Work better with sorted array
  size = len(array)
  for i in range(1,size):
    j = i
    while j > 0 and array[j] < array[j-1]:
      swap(array,j,j-1)
      j -= 1

def shell_sort(array):
  # Idea: Based on insertion sort, but exchange values which are far apart
  # First sort array by gap N and then decrease gradually
  size = len(array)
  h = 1
  while h < size / 3:
    h = h * 3 + 1
  while h >= 1:
    for i in range(h,size):
      j = i
      while j >= h and array[j] < array[j-h]:
        swap(array,j,j-h)
	j -= h
    h = h / 3
  
def merge(array,aux,lo,mid,hi):
  # copy array to aux
  # loop through lo to hi + 1!!!!!!!!!!!!!!!!
  # if  i > mid just copy right half
  # if  j > hi copy left half
  # else choose the smaller one
  # remeber loop go from lo to hi + 1
  i = lo
  j = mid + 1

  for k in range(lo,hi+1):
    aux[k] = array[k]

  for k in range(lo,hi+1):
    if i > mid:
      array[k] = aux[j]
      j += 1
    elif j > hi:
      array[k] = aux[i]
      i += 1
    elif aux[i] < aux[j]:
      array[k] = aux[i]
      i += 1
    else:
      array[k] = aux[j]
      j += 1

def merge_sort(array,aux,lo,hi):
  # Idea: divide to atomic unit and compare and merge 
  # if hi <= lo BASE CASE!!!!!! 
  if hi <= lo:
    return
  mid = lo + (hi - lo) / 2
  merge_sort(array,aux,lo,mid)
  merge_sort(array,aux,mid+1,hi)
  merge(array,aux,lo,mid,hi)

def merge_sort_wrapper(array,aux):
  merge_sort(array,aux,0,len(array)-1)

def partition(array,lo,hi):
  # [i(comp)......j]
  # result [ all small than comp, comp, all larger than comp]
    pivot = lo
    for i in xrange(lo+1, hi+1):
      if array[i] <= array[lo]:
        pivot += 1
	swap(array,i,pivot)
    swap(array,pivot,lo)
    return pivot

def quick_sort(array,lo,hi):
  # Idea: divide and conquer, if subarrays are sorted, whole array is sorted 
  # BASE CASE
  if hi <= lo:
    return
  j = partition(array,lo,hi)
  quick_sort(array,lo,j-1)
  quick_sort(array,j+1,hi)

def quick_sort_wrapper(array):
  quick_sort(array,0,len(array)-1)

def shift_down(array,start,end):
  root = start
  while True:
    child = 2 * root + 1
    if child > end:
      break
    if child + 1 <= end and array[child] < array[child+1]:
      child += 1
    if array[root] < array[child]:
      swap(array,root,child)
      root = child
    else:
      break

def heap_sort(array):
  # heapify
  size = len(array)
  for beg in xrange((size-2)/2, -1 , -1):
    shift_down(array,beg,size-1)
  
  # sort 
  for end in xrange(size - 1, 0 , -1):
    swap(array,0,end)
    shift_down(array, 0 , end - 1 )

def sort_run():
  # Generating random int array
  rand = []
  for i in range(int(sys.argv[1])):
    rand.append(random.randint(1,100))
  print "I have generated random int array that has {0} numbers".format(sys.argv[1])

  names = ["selection_sort","insertion_sort","shell_sort","merge_sort","quick_sort","heap_sort"]

  # Running selection sort
  randcopy = rand[:]
  name = names[0]
  beg = time.time()
  selection_sort(randcopy)
  end = time.time()
  if not is_sorted(randcopy):
    raise Exception("NOT SORTED!!!")
  else:
    print("[{0:15s}] has run {1:.5f} seconds".format(name,end-beg))

  # Running insertion sort
  randcopy = rand[:]
  name = names[1]
  beg = time.time()
  insertion_sort(randcopy)
  end = time.time()
  if not is_sorted(randcopy):
    raise Exception("NOT SORTED!!!")
  else:
    print("[{0:15s}] has run {1:.5f} seconds".format(name,end-beg))

  # Running shell sort
  randcopy = rand[:]
  name = names[2]
  beg = time.time()
  shell_sort(randcopy)
  end = time.time()
  if not is_sorted(randcopy):
    raise Exception("NOT SORTED!!!")
  else:
    print("[{0:15s}] has run {1:.5f} seconds".format(name,end-beg))

  # Merge sort
  randcopy = rand[:]
  name = names[3]
  beg = time.time()
  aux = randcopy[:]
  merge_sort_wrapper(randcopy,aux)
  end = time.time()
  if not is_sorted(randcopy):
    raise Exception("NOT SORTED!!!")
  else:
    print("[{0:15s}] has run {1:.5f} seconds".format(name,end-beg))

  # Quick sort
  randcopy = rand[:]
  name = names[4]
  beg = time.time()
  aux = randcopy[:]
  quick_sort_wrapper(randcopy)
  end = time.time()
  if not is_sorted(randcopy):
    raise Exception("NOT SORTED!!!")
  else:
    print("[{0:15s}] has run {1:.5f} seconds".format(name,end-beg))


  # Heap_sort
  randcopy = rand[:]
  name = names[5]
  beg = time.time()
  aux = randcopy[:]
  heap_sort(randcopy)
  end = time.time()
  if not is_sorted(randcopy):
    raise Exception("NOT SORTED!!!")
  else:
    print("[{0:15s}] has run {1:.5f} seconds".format(name,end-beg))
  

if __name__ == "__main__":
  sort_run()

'''
Takeaways:

It is not only time and space complexity, but also depends on cost of opeartions(comparison,move)
'''
