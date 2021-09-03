def bfs(rPath, s, exits, parent):
    v = len(rPath)
    vis = [False for i in range(v)]
    q = []
    q.insert(0,s)
    vis[s]=True
    parent[s]=-1
    
    while(len(q)>0):
        ver = q.pop()
        for i in range(v):
            if vis[i]==False and rPath[ver][i]>0:
                if i in exits:
                    parent[i] = ver
                    return (True,i)
                
                parent[i]=ver
                vis[i]=True
                q.insert(0,i)
    
    return (False, -1)

def maxFlow(rPath, s, exits):
    parent=[-1 for i in range(len(rPath))] 
    res = bfs(rPath, s, exits, parent)
    max_flow=0
    while(res[0]):
        v=res[1]
        path_flow=1e9
        while(v!=s):
            u = parent[v]
            path_flow = min(path_flow, rPath[u][v])
            v=parent[v]
    
        max_flow += path_flow
        
        v=res[1]
        while(v!=s):
            u = parent[v]
            rPath[u][v] -= path_flow
            rPath[v][u] += path_flow
            v=parent[v]
        
        res = bfs(rPath, s, exits, parent)
    
    return max_flow


def solution(entrances, exits, path):
    rPath = path
    maxflow = 0
    for s in entrances:
        maxflow+=maxFlow(rPath, s, exits)
    
    return int(maxflow)
    
