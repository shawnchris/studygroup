class ugraph:
  '''
  REPRESENTATION 1: adjacent list
  adj[vertex] 
    [
      0: 1-3-5
      1: 0-4-2
      ....
    ]
  '''

  def __init__(self,v):
    self._verticeCount = v
    self._edgeCount = 0
    self._adj= []
    for i in range(v):
      self._adj.append([None])

  def addEdge(self,v1,v2):
    self._adj[v1].append(v2)
    self._adj[v2].append(v1)
    self._edgeCount += 1

  def vsize(self):
    return self._verticeCount

  def esize(self):
    return self._edgeCount

class digraph:
  pass

  def addEdge(self,v1,v2):
    self._adj[v1].append(v2)
    # DO NOT ADD v1 in adj[v2]
    self._edgeCount += 1

# What graph search do: 1.find whether vertex is accessible. 2.find the exact path to this vertex

class dfs:
  # dfs(g,v) loop through v.adjacent vertices
  # mark the vertices that has been reached.
  _marked = []
  _count = 0
  _edgeTo = []

  def __init__(self,g,s):
    self._marked = [None]*g.vsize()
    run(g,s)

  def run(self,g,v):
    self._marked[v] = True
    for i in len(g._adj[v]):
      if not marked[i]:
        _edgeTo[i] = v
	self.run(g,w)
    

if __name__ == "__main__":
  graph = ugraph(10)
  print graph.vsize()
  print graph.esize()
  print graph._adj
