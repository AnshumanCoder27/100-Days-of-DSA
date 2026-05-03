import subprocess
import random
from datetime import datetime, timedelta

# Weighted probabilities (1 is rare, 4 is common)
commit_weights = {
    1: 1,
    2: 2,
    3: 3,
    4: 5,
    5: 2
}

def weighted_choice(weights):
    total = sum(weights.values())
    r = random.uniform(0, total)
    upto = 0
    for k, w in weights.items():
        if upto + w >= r:
            return k
        upto += w

def run_git_command(env):
    subprocess.run(
        ["git", "commit", "--allow-empty", "-m", "update"],
        env=env,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL
    )

# Input dates
start_date = input("Enter start date (YYYY-MM-DD): ")
end_date = input("Enter end date (YYYY-MM-DD): ")

start = datetime.strptime(start_date, "%Y-%m-%d")
end = datetime.strptime(end_date, "%Y-%m-%d")

current = start

while current <= end:
    num_commits = weighted_choice(commit_weights)

    for _ in range(num_commits):
        random_time = current + timedelta(
            hours=random.randint(0, 23),
            minutes=random.randint(0, 59),
            seconds=random.randint(0, 59)
        )

        date_str = random_time.strftime("%Y-%m-%d %H:%M:%S")

        env = {
            **subprocess.os.environ,
            "GIT_AUTHOR_DATE": date_str,
            "GIT_COMMITTER_DATE": date_str
        }

        run_git_command(env)

    current += timedelta(days=1)

print("Done generating commits.")