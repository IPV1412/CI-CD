import random
import statistics
import datetime


# Simular la situación de despliegues
deploys = []
for i in range (20):
    commit_time = (datetime.datetime(2025, 9, 9, 9,17) +
                  datetime.timedelta(hours=i * 4))
    deploy_time = commit_time + datetime.timedelta (hours=random.randint( 1, 12))
    recovery_time = deploy_time + datetime.timedelta (hours=random.randint(1, 5))
    deploys.append({
        "commit_time:": commit_time,
        "deploy_time: ": deploy_time,
        "recovery_time:": recovery_time
    })

# Calcular métricas
lead_times =[(d["deploy_time"]-d["commit_time"]).total_seconds()/3600
             for d in deploys]
mttr = [(d["recovery_time"]-d["deploy_time"]).total_seconds()/3600
        for d in deploys]

print("Lead Time promedio (horas):",
      round(statistics.mean(lead_times),2))
print("MTTR promedio (horas):",
      round(statistics.mean(mttr),2))


