from collections import deque

n, m, s = map(int, input().split())
g = {i: [] for i in range(1, n + 1)}
gt = {i: [] for i in range(1, n + 1)}
for i in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    gt[v].append(u)

visited = {i: False for i in range(1, n + 1)}
stk = deque()

def visit(root):
    if not visited[root]:
        visited[root] = True
        for nbr in g[root]:
            visit(nbr)
        stk.appendleft(root)

for i in range(1, n + 1):
    visit(i)

#print(stk)

component = {i: -1 for i in range(1, n + 1)}

def assign(u, root):
    if component[u] == -1:
        component[u] = root
        for v in gt[u]:
            assign(v, root)

for u in stk:
    assign(u, u)

#print(component)

component_indices = set(component.values())
scc = {i: [] for i in component_indices}
indeg = {i: 0 for i in component_indices}

for u in range(1, n + 1):
    for v in g[u]:
        if component[u] != component[v]:
            scc[component[u]].append(component[v])
            indeg[component[v]] += 1

#print(scc)
#print(indeg)

seen = {x: False for x in component_indices}
stk = [component[s]]
#print(stk)
while stk:
    curr = stk.pop()
    #print("curr: ", curr)
    if not seen[curr]:
        #print("Here")
        seen[curr] = True
        for adj in scc[curr]:
            stk.append(adj)

#print(seen)

ans = 0
for i in component_indices:
    if not seen[i] and indeg[i] == 0:
        ans += 1

print(ans)