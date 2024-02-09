from fastapi import FastAPI, Response, status
from pydantic import BaseModel

app = FastAPI()

# localhost:8080/

# NOTES

users = set()
# username: password

class User(BaseModel):
    username: str

@app.get("/users")
async def root():
    return users

@app.get("/users")
async def root(username: str):
    print(username)
    return users

@app.post("/users")
async def root(response: Response, user: User, x: int):
    print(x)

    if user.username in users:
        response.status_code = status.HTTP_409_CONFLICT
        return "Error!"

    users.add(user.username)

@app.delete("/users")
async def root(user: User, response: Response):
    if user.username not in users:
        response.status_code = status.HTTP_409_CONFLICT
        return "Error!!"

    users.remove(user.username)
