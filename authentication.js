const express = require("express")
const app = express()
const zod = require("zod")
const jwt = require("jsonwebtoken")
const secret = "12345"
app.use(express.json())

const userSchema = zod.string().email();
const passwordSchema = zod.string().min(6);


function userMiddleware(req,res,next)
{
    const user = req.body.user;
    const password = req.body.password;

    const userResponse = userSchema.safeParse(user);
    const passwordresponse = passwordSchema.safeParse(password);

    if(!userResponse.success || !passwordresponse.success)
    {
        res.status(411).json({
            msg : "user authentication failed"
        })
    }
    
    const token = jwt.sign({user : user} , secret);
    next()
}

app.use(userMiddleware)

app.get('/users' , (req,res) => {
    console.log("hitted users route");
})

app.listen(3000 , () => {
    console.log("app is listening at port 3000");
})