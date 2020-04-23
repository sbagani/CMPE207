var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);


app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', function(socket){
socket.on('userName', function(userName){
  socket.userName=userName;
  io.emit('is_online', '🟢 <i>' + socket.userName + ' is now in the chat</i>');
});

socket.on('disconnect', function(userName) {
        io.emit('is_online', '🔴 <i>' + socket.userName + ' just left the chat</i>');
    })

    socket.on('chat_text', function(message) {
        io.emit('chat_text', '<strong>' + socket.userName + '</strong>: ' + message);
    });

});

 const server = http.listen(5000, function(){
  console.log('listening on port :5000');
});
