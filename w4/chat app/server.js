const io = require('socket.io')(3000);

const users = {};

io.on('connection', socket => {
  socket.on('new-user', name => {
    users[socket.id] = name;
    socket.broadcast.emit('user-connected', name);
  });

  socket.on('send-mes', mes => {
    socket.broadcast.emit('chat-mes', {mes: mes, user: users[socket.id]});
  });

  socket.on('disconnect', e => {
    socket.broadcast.emit('user-disconnected', users[socket.id]);
    delete users[socket.id];
  });
});
