"""
The code frame is from midterm sample
"""
import subprocess
import sys
import csv
import argparse

EXEC = "./fib.out"
COMMON_ARG_FORMAT = "{n} {type}"
TIMEOUT = 60
OUT_DEFAULT = "fib_run.csv"
OUT_FILE_TIME = "timings_"
OUT_FILE_OPS = "ops_"
CSV_HEADER = "N,Iterative,Dynamic Programming,Recursive"


class RecursionTimeoutError(Exception):
    pass


def run_single(n: int, typ: int) -> dict:
    """Run a single instance collecting the values into a dictionary
    with two tuples, one for timings and one for operations

    Args:
        n (int): the row to generate
        typ (int): the type of algorithm to use

    Returns:
        float: the time it took, or nan if TIMEOUT is reached first
    """
    try:
        command = f"{EXEC} {n} {typ}"
        results = subprocess.run(
            command.split(), timeout=TIMEOUT, capture_output=True, text=True
        )
    except subprocess.TimeoutExpired:
        raise RecursionTimeoutError(f"Timeout of {TIMEOUT} seconds reached for {args}")

    if results.returncode != 0:
        raise Exception(f"Error running {args}: {results.stderr}")

    results_line = results.stdout.strip().split(",")
    timings = []
    operations = []
    for i in range(0, len(results_line), 2):
        timings.append(results_line[i])
        operations.append(results_line[i + 1])

    return {"timings": timings, "operations": operations}


def save_to_csv(values: list, out_file: str, step):
    """saves a list to a csv file
    Args:
        results (list): the results to save
        out_file (str): the base file name to write to
    """
    with open(out_file, "w", newline="") as f:
        csv_writer = csv.writer(f)
        csv_writer.writerow(CSV_HEADER.split(","))
        for i, row in enumerate(values):
            row = [i*step + 1] + row
            csv_writer.writerow(row)


def main(n, step=1, out_file=OUT_DEFAULT):
    run_type = 4
    results = {"timings": [], "operations": []}
    for i in range(1, n + 1, step):
        try:
            result = run_single(i, run_type)
            results["timings"].append(result["timings"])
            results["operations"].append(result["operations"])
        except RecursionTimeoutError as e:
            run_type = 4
            result = run_single(i, run_type)
            results["timings"].append(result["timings"])
            results["operations"].append(result["operations"])
        except Exception as e:
            print(e, file=sys.stderr)
            break # if i hit this I have to try to end the loop
    save_to_csv(results["operations"], OUT_FILE_OPS + out_file,step)
    save_to_csv(results["timings"], OUT_FILE_TIME + out_file,step)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Run the fib array program")
    parser.add_argument("n", type=int, help="the number of rows to generate")
    parser.add_argument("--step", type=int, default=1, help="the step size")
    parser.add_argument(
        "--out", type=str, default=OUT_DEFAULT, help="the output file name"
    )
    parser.add_argument(
        "--timeout", type=int, default=TIMEOUT, help="the timeout in seconds"
    )
    parser.add_argument("--exec", type=str, default=EXEC, help="the executable to run")
    args = parser.parse_args()
    TIMEOUT = args.timeout  # reset them if needed
    EXEC = args.exec
    main(args.n, args.step, args.out)
