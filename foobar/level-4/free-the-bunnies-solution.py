from itertools import combinations

def solution(num_buns, num_required):
    bunny_keys = [[] for n in range(num_buns)]
    copies = num_buns - num_required + 1
    
    for keynum, keyholder in enumerate(combinations(range(num_buns), copies)):
        for idx in keyholder:
            bunny_keys[idx].append(keynum)
            
    
    return bunny_keys
