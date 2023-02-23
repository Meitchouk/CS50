import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():

    if request.method == "POST":
        # si no hay nombre, mes o dia, mostrar mensaje de error
        message = ""
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        if not name:
            # si no hay nombre, mostrar mensaje de error
            message = "Missing name"
        elif not month:
            # si no hay mes, mostrar mensaje de error
            message = "Missing month"
        elif not day:
            # si no hay dia, mostrar mensaje de error
            message = "Missing day"
        else:
            # si hay nombre, mes y dia, insertar en la base de datos
            db.execute(
                "INSERT INTO birthdays (name, month, day) VALUES(?, ?,?)",
                name,
                month,
                day,
            )
        birthdays = db.execute("SELECT * FROM birthdays")
        # mostrar mensaje de error si es necesario
        return render_template("index.html", message=message, birthdays=birthdays)
        # si no es POST, mostrar la pagina principal
    else:
        # pero antes, obtener los cumpleaños de la base de datos
        birthdays = db.execute("SELECT * FROM birthdays")
        # si no es POST, mostrar la pagina principal con los cumpleaños de la base de datos
        return render_template("index.html", birthdays=birthdays)
        # y retornar la pagina principal


