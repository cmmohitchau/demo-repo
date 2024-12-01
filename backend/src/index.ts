import express from "express";
const app = express();
app.use(express.json());


const PORT = 3000;

app.get('/' , async (req , res) => {
    const body = await req.body;

    res.status(200).json({
        username : body.username,
        name : body.name
    })
})

app.listen(PORT , () => {
    console.log(`app is listening on PORT${PORT}`);
    
})