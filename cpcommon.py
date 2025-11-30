from pathlib import Path
import sys, re, shutil, os

def save_file(problem: str, dst_dir: str, src_file: str = "main.cpp"):
    # Convert argument to kebab case
    arg = problem.strip()
    name = re.sub(r'[^a-zA-Z0-9]+', '-', arg).strip('-').lower()

    # Pad leading number to 6 digits
    match = re.match(r'^(\d+)(.*)', name)
    if match:
        number, rest = match.groups()
        name = f"{int(number):06d}{rest}"

    dst_dir = str(Path(__file__).parent / dst_dir)
    dst = str(Path(__file__).parent / dst_dir / f"{name}.cpp")

    os.makedirs(dst_dir, exist_ok=True)

    # Abort if target already exists
    if os.path.exists(dst):
        print(f"Error: {dst} already exists. Aborting.")
        sys.exit(1)

    shutil.copy(src_file, dst) # pyright: ignore [reportUnusedCallResult]
    print(f"Copied {src_file} -> {dst}")
