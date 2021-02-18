# Flask Tutorial

Flask is a micro framework written in Python for use in building backend APIs, as well as hosting web pages.

**_Disclaimer_: This tutorial assumes you are using a linux distro, have prior knowledge of the Python programming language, and are using Python3.6 or newer.**

## Installation

Download flask using pip:

```bash
$ pip install --user flask
```

Create a directory for your flask project:

```bash
$ mkdir hello-flask
$ cd hello-flask
$ touch app.py
```

Note that your app can be called anything, I chose to name it _app_ as it makes it easier to start the server.

Open `app.py` using your favorite text editor and import flask:

```python
import flask
```

Next, let's create our Flask app object, this object will handle our api routes.

```python
app = flask.Flask(__name__)
app.config['DEBUG'] = True
```

Don't worry if you don't know what this does yet; we've just declared our Flask object and have configured it to be in debug mode as this project is still in development. This configuration line can be removed when your project is deployed and in production.

Let's create our first api route, we'll have it send some JSON data:

```python
@app.route('/', methods=['GET'])
def hello():
    response = {'hello': 'flask'}
    return flask.jsonify(response)
```

There are a few things going on here. First, we're routing the root of the server to the `hello()` function. So if we run our server using localhost, requesting "http://localhost:5000/", our server will return the json data `{"hello": "flask"}` because of the forward slash. This is why visiting "https://youtube.com/" will bring you to YouTube's homepage, but visiting "https://youtube.com/feed/subscriptions" will bring you to your subscriptions (assuming you're logged in of course): the first route ("/") points to the home page, but second route ("/feed/subscriptions") points to your subscription list.

Our `hello()` function is wrapped in another method that belongs to our `app` object, this `app.route()` is what the server uses to send web requests to the right function in our application. Notice that I have also passed a methods parameter, this tells `app.route` that our endpoint only accepts GET requests (meaning it simply returns data). As you build your application, you'll accept other requests such as POST requests (this is the request that's sent whenever you make server side changes with a request, such as logging in to YouTube, for example).

Finally, our response data is declared as a python dict literal and is passed to flasks's `jsonify` method. This method creates web compliant JSON data using either an existing dictionary, or built from keyword arguments passed directly to `jsonify`.

Now that we have our first route built, let's spin up our server:

```python
app.run(debug=True, host='127.0.0.1', port=5000)
```

Once we execute this script, this will start the flask server in debug mode @localhost on port 5000, meaning it will automatically restart the server if we make any changes to our code (which is helpful for testing and, well, _debugging_) as well as dump a traceback if any errors occur that will show up both in the terminal and at "http://localhost:5000" as an aesthetically pleasing table of error messages. Note that these keyword arguments are not all necessary: `host` defaults to localhost, `port` (usually) defaults to 5000; the `debug` flag defaults to False however, so remember to set it to True while you're building and testing your application.

The full script:

```python
import flask

app = flask.Flask(__name__)
app.config['DEBUG'] = True

@app.route('/', methods=['GET'])
def hello():
    response = {'hello': 'flask'}
    return flask.jsonify(response)

app.run(debug=True, host='127.0.0.1' port=5000)
```

Running the app in the terminal:

```bash
$ python app.py
```

If you chose to name your app something other than "app" you'll have to run your server using this command instead:

```bash
$ export FLASK_APP=<app name>.py
$ python -m flask run
 * Running on http://127.0.0.1:5000/
```

Where `<app name>` is the name you gave to your flask app.

Now, if you go that web address, you'll see our jSON data `{"hello": "flask"}` displayed.

However, what if we wanted to fetch data from our API without opening up a browser? We can use the `requests` package:

```bash
$ pip install requests
$ touch fetch_api_data.py
```

Requests is a python package that allows us to request web data from various APIs as well as raw html content. Let's write a script to grab the JSON data from our flask API.

```python
import requests

url = 'http://127.0.0.1:5000/'
request = requests.get(url)
if request.ok:
    print(request.json())
```

Passing the url of our flask API to the `requests.get()` method is just like typing the address into your browser. If the status code of the GET requests is OK (this usually means a status code of 200, but any status code in the 2xx range is considered a successful request), our `request` object will then receive the API data, which can be accessed with the object's `json()` method. Let's run our flask api in the background, then run our request script:

```bash
$ python hello-flask/app.py &
$ python fetch_api_data.py
$ {'hello': 'flask'}
```

You can kill the background flask application by running:

```bash
$ fuser -k -n tcp 5000
```

5000 is the port number we used for this tutorial, you can swap it with whichever port you may have decided to use.

This tutorial only covers a subset of what the flask and requests packages can do, to learn more follow this links:

[Python Flask Tutorial/Docs](https://flask.palletsprojects.com/en/1.1.x/quickstart/)

[Python requests docs](https://requests.readthedocs.io/en/master/)