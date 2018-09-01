# states that can be recovered
states_needed = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])
# brocast stations list and states recovered by these stations
stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "az"])
stations["kfive"] = set(["ca", "az"])

final_stations = set()

while states_needed:
	best_station = None
	states_covered = set()
	for station, states_for_station in stations.items():
		# calculate the intersection of the given two sets
		covered = states_needed & states_for_station;
		# select the station which can cover the most states uncovered 
		if len(covered) > len(states_covered):
			best_station = station
			states_covered = covered

	final_stations.add(best_station)
	states_needed -= states_covered

print(final_stations)